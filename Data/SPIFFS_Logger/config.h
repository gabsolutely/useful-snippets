// SPIFFS_Logger/config.h
#pragma once

// CSV logging (please adjust as needed)
#define CSV_PATH           "/data/log.csv"
#define CSV_FILE_LIMIT     1048576   // 1 MB
#define CLEAR_CSV_ON_BOOT  true

// time fallback
#define EPOCH_OFFSET       1700000000 // Fallback epoch time
