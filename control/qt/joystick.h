#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <serial.h>
#include <string>
#include <vect.h>

class joystick: public serial
{
private:
    bool power_switch;
    number_vect_t power_value;

    vect data, data_default;
    static const number_vect_t MAX_VALUE = 1023;
    static const number_vect_t MIN_VALUE = 0;

    static const number_vect_t MAX_POWER_VALUE = 1023;

    void defaults();

public:
    joystick();

    void connect();
    void disconnect();

    void set_data_default(); // set zero position
    void read_data(); // read data from device

    vect get_readings(); // 2D vect, values [0...1]
    bool is_switched_on();
    number_vect_t get_power_value();
};

#endif // JOYSTICK_H
