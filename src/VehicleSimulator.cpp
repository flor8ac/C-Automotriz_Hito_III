#include "vehiclesimulator.h"
#include <random>

VehicleSimulator::VehicleSimulator(unsigned int seed) : seed(seed) {}

void VehicleSimulator::simulateVehicle(std::vector<Sensor>& sensors, int cycle) {
    static std::mt19937 generator(seed);
    std::uniform_real_distribution<double> speedChange(-4.0, 6.0);
    std::uniform_real_distribution<double> tempNoise(-1.5, 1.5);
    std::uniform_real_distribution<double> voltNoise(-0.1, 0.1);

    for (auto& sensor : sensors) {
        if (sensor.getName() == "Velocity") {
            if (cycle == 12) {
                sensor.registerUnupdatedCycle();
                continue;
            }
            double newVal = sensor.getValue() + speedChange(generator);
            if (newVal < 0) newVal = 0;
            sensor.update(newVal);
        }
        else if (sensor.getName() == "RPM") {
            double newVal = 800.0 + (sensors[0].getValue() * 25.0);
            sensor.update(newVal);
        }
        else if (sensor.getName() == "Temperature") {
            if (cycle == 20) {
                sensor.update(135.0); // Out of range trigger
            } else {
                double newVal = sensor.getValue() + tempNoise(generator);
                sensor.update(newVal);
            }
        }
        else if (sensor.getName() == "Battery Voltage") {
            double newVal = 13.8 + voltNoise(generator);
            sensor.update(newVal);
        }
        else if (sensor.getName() == "Oil Pressure") {
            double newVal = 2.5 + voltNoise(generator);
            sensor.update(newVal);
        }
    }
}