#pragma once

#pragma once
#include <vector>
#include "sensor.h"

class VehicleSimulator {
private:
    unsigned int seed;

public:
    VehicleSimulator(unsigned int seed = 12345);
    void simulateVehicle(std::vector<Sensor>& sensors, int cycle);
};