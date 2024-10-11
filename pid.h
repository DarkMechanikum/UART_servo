#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PIDController {
public:
    PIDController(float kp, float ki, float kd, int setpoint);
    int update(int current_value, float dt);

private:
    float kp;         // Proportional gain
    float ki;         // Integral gain
    float kd;         // Derivative gain
    int setpoint;     // Desired target value
    float integral;   // Integral term
    float previous_error;  // Previous error term
};

#endif // PIDCONTROLLER_H
