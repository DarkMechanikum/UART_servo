#include "PIDController.h"

PIDController::PIDController(float kp, float ki, float kd, int setpoint)
    : kp(kp), ki(ki), kd(kd), setpoint(setpoint), integral(0), previous_error(0) {}

int PIDController::update(int current_value, float dt) {
    float error = setpoint - current_value;
    integral += error * dt;
    float derivative = (error - previous_error) / dt;

    float output = kp * error + ki * integral + kd * derivative;
    previous_error = error;

    return static_cast<int>(output); // Returning output power level
}
