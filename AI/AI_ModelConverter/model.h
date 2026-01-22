#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void score_class1(double * input, double * output);
void score_class2(double * input, double * output);
void score_class3(double * input, double * output);
void score_class4(double * input, double * output);

int runAIModel(float feature1, float feature2, float feature3, float feature4);

#ifdef __cplusplus
}
#endif
