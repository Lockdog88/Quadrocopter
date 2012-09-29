#ifndef QUADROCOPTER_H
#define QUADROCOPTER_H

#include <serial.h>
#include <vect.h>
#include <vector>

using std::vector;

class quadrocopter: public serial
{
public:
    enum reaction_type_ {REACTION_NONE, REACTION_ANGULAR_VELOCITY, REACTION_ACCELERATION, REACTION_ANGLE};
private:
    number_vect_t power;
    vect angle, torque_corrected;
    vect gyroscope_readings, accelerometer_readings;
    vect torque_angular_velocity_correction, torque_acceleration_correction, torque_angle_correction;

    vect torque_manual_correction;

    static const int MOTORS_N = 4;
    number_vect_t MOTORS[MOTORS_N];

    reaction_type_ reaction_type;

    number_vect_t read_time, write_time, loop_time;

    static const double g = 9.80665;

    number_vect_t connect_delay_arduino;

    number_vect_t PID_angle_Kp, PID_angle_Ki, PID_angle_Kd;
    number_vect_t PID_angular_velocity_Kp, PID_angular_velocity_Ki, PID_angular_velocity_Kd;

    number_vect_t joystick_coefficient;

    void defaults();

    void read_data(); // read data from device

public:

    quadrocopter();

    number_vect_t get_power(); // returns power [0...1]
    vect get_torque_corrected(); // returns vect torque_corrected
    vect get_torque_manual_correction(); // returns vect torque_manual_correction
    int get_motors_n(); // returns MOTORS_N
    number_vect_t get_motor_power(int); // returns motor power [0...1]
    vect get_gyroscope_readings(); // returns gyroscope readings, values [0...1]
    vect get_accelerometer_readings(); // returns acceleromter readings, values [0...]
    vect get_angle(); //returns angle, values [0...1]

    vect get_torque_angular_velocity_correction();
    vect get_torque_acceleration_correction();
    vect get_torque_angle_correction();

    void set_power(number_vect_t);
    void set_torque_manual_correction(vect);
    void set_joystick_correction(vect);

    void set_PID_angle_Kp(number_vect_t);
    void set_PID_angle_Ki(number_vect_t);
    void set_PID_angle_Kd(number_vect_t);

    void set_PID_angular_velocity_Kp(number_vect_t);
    void set_PID_angular_velocity_Ki(number_vect_t);
    void set_PID_angular_velocity_Kd(number_vect_t);

    number_vect_t get_PID_angle_Kp();
    number_vect_t get_PID_angle_Ki();
    number_vect_t get_PID_angle_Kd();

    number_vect_t get_PID_angular_velocity_Kp();
    number_vect_t get_PID_angular_velocity_Ki();
    number_vect_t get_PID_angular_velocity_Kd();

    void do_connect();
    void do_disconnect();

    number_vect_t get_read_time(); //last read time in sec
    number_vect_t get_write_time(); //last write time in sec
    number_vect_t get_loop_time(); //last loop time in sec

    reaction_type_ get_reaction_type();
    void set_reaction_type(reaction_type_);

    void read_data_request(); // request read data from device
    void write_data(); // write data to device

    void reset(); // set torque to (0, 0, 1)

    virtual void on_rx();
};

#endif // QUADROCOPTER_H
