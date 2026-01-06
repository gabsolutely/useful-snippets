// Logger.cpp

#include "Logger.h"
#include <SPIFFS.h> // Include the SPIFFS library
#include <FS.h> // Include the FS library for file system operations
#include <time.h> // Include time library for timestamping
#include "config.h"

// helper to get epoch time, with fallback if NTP not synced
static time_t getEpoch() {
    time_t now;
    time(&now);
    if (now < 100000) { // NTP not synced
        now = millis() / 1000 + EPOCH_OFFSET; // adjust offset to a close default
    }
    return now;
}

// clear CSV file content
void Logger::clearCSV() {
    if (SPIFFS.exists(CSV_PATH)) {
        SPIFFS.remove(CSV_PATH);
        Serial.println("[LOGGER] CSV cleared");
    }
}

void Logger::init() {
    // check SPIFFS mount
    if (!SPIFFS.begin(true)) {
        Serial.println("[LOGGER] SPIFFS mount failed");
        return;
    }

    // create data directory if not exists
    if (!SPIFFS.exists("/data")) {
        SPIFFS.mkdir("/data");
    }

    // clear CSV on boot if configured
    if (CLEAR_CSV_ON_BOOT && SPIFFS.exists(CSV_PATH)) {
        Logger::clearCSV();
    }

    File f = SPIFFS.open(CSV_PATH, FILE_APPEND);
    if (!f) {
        Serial.println("[LOGGER] CSV open failed");
        return;
    }

    // write CSV header if file is empty
    if (f.size() == 0) {
        f.println("ts,temp,avgTemp,humidity,avgHumidity,light,avgLight,motion,action");
    }

    // close and list files
    f.close();
    Serial.println("[LOGGER] Ready");
    Serial.println("[LOGGER] SPIFFS File List: ");
    File root = SPIFFS.open("/");
    File file = root.openNextFile();
    while (file) {
        Serial.print("FILE: ");
        Serial.println(file.name());
        file = root.openNextFile();
    }
    root.close();
}

// append a new log entry
void Logger::append(float temp, float avgTemp, float hum, float avgHum,
                    int light, int avgLight, int motion, int action) {

    // open CSV file for appending
    File f = SPIFFS.open(CSV_PATH, FILE_APPEND);
    if (!f) {
        Serial.println("[LOGGER] Append failed");
        return;
    }

    // check file size limit
    if (f.size() > CSV_FILE_LIMIT) {
        Serial.println("[LOGGER] CSV file size limit exceeded, logging stopped");
        f.close();
        return;
    }

    // get current timestamp
    time_t ts = getEpoch();
    struct tm timeinfo;
    localtime_r(&ts, &timeinfo);

    char timestr[9];
    strftime(timestr, sizeof(timestr), "%H:%M:%S", &timeinfo);

    // write CSV line
    f.printf(
        "%s,%.2f,%.2f,%.2f,%.2f,%d,%d,%d,%d\n",
        timestr,
        temp, avgTemp,
        hum, avgHum,
        light, avgLight,
        motion, action
    );

    // finalize
    f.flush();
    f.close();
}

// OPTIONAL: build JSON payload for network transmission (e.g., HTTP POST)
void Logger::buildPayload(float temp, float avgTemp, float hum, float avgHum,
                          int light, int avgLight, int motion, int action, char* out, size_t maxLen) {
    // build JSON payload
    // placeholder implementation
    snprintf(
        out, maxLen,
        "{\"ts\":%lu,\"temp\":%.2f,\"avgTemp\":%.2f,"
        "\"humidity\":%.2f,\"avgHumidity\":%.2f,"
        "\"light\":%d,\"avgLight\":%d,"
        "\"motion\":%d,\"action\":%d}",
        getEpoch(),
        temp, avgTemp,
        hum, avgHum,
        light, avgLight,
        motion, action
    );
}