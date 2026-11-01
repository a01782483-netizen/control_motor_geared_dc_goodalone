#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include "RPM_CONTROLLER.h"

#define ENCODER_OUT GPIO_NUM_26
#define PWM_OUT GPIO_NUM_27
#define SAMPLING_TIME 100
#define DIR_1 GPIO_NUM_14
#define DIR_2 GPIO_NUM_12

//first white an dthen red, yellowto esp32.supply 3.3v for encoder esp, power with 5 v driver.


float kp = 0.01f; //0.2
float ki = 0.3f; //1
float out_pwm = 0.0f;

#endif // __DEFINITIONS_H__
