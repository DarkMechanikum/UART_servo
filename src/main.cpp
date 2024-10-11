#include <iostream>
#include <chrono>
#include <thread>
#include "PIDController.h"

// Mock functions to simulate
void setMotorPower(int level) {
    std::cout << "Setting motor power to: " << level << std::endl;
}
void setMotorDirection(bool direction) {
    std::cout << "Setting motor direction to: " << (direction ? "Clockwise" : "Counterclockwise") << std::endl;
}
int getMotorSpeed() {
    static int simulated_speed = 0;
    // Random fluctuations for simulation purposes
    simulated_speed += (rand() % 10) - 5;
    return simulated_speed;
}

int main() {
    // PID coefficients
    float kp = 1.0;
    float ki = 0.1;
    float kd = 0.05;

    // Desired setpoint
    int setpoint_rpm = 1000;

    PIDController pid(kp, ki, kd, setpoint_rpm);

    // Simulation loop
    auto previous_time = std::chrono::high_resolution_clock::now();
    while (true) {
        // Get the current motor speed
        int current_speed = getMotorSpeed();

        // Calculate the time elapsed
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = current_time - previous_time;
        previous_time = current_time;
        float dt = elapsed.count();

        // Update the PID controller
        int power_output = pid.update(current_speed, dt);

        // Set motor power and direction based on PID output
        setMotorPower(power_output);

        // Small delay to simulate real-time control
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
