#ifndef __RPM_CONTROLLER_H__
#define __RPM_CONTROLLER_H__

#include <SimplePWM.h>
#include <SimpleGPIO.h>

#define DEBOUNCET 0


class RPM_CONTROLLER
{
public:
    RPM_CONTROLLER();
    void setup(gpio_num_t encoder_pin, uint32_t sample_time_ms);
    void setPI(float kp, float ki);
    float rpm(float desired_rpm);
    float getRPM() const { return _last_rpm; }

private:
    SimpleGPIO _Encoder;
    gpio_num_t _encoder_pin;
    uint32_t _sample_time_ms;
    uint64_t _timer;
    float _last_rpm = 0.0f;
    volatile uint32_t _pulse_count = 0;
    static void IRAM_ATTR interr_encoder(void *arg);
    static RPM_CONTROLLER* _instance;
    float _kp = 0.0f;
    float _ki = 0.0f;
    float _error_CL = 0.0f;
    float _integral = 0.0f;

    float _adj_pwm = 0.0f;
};

#endif // __RPM_CONTROLLER_H__