#pragma once
#include <vector>
#include "sensor.h"
#include "ecucontrol.h"

class Dashboard {
public:
    Dashboard();
    void render(const std::vector<Sensor>& sensors, ECUState controlState, int cycle) const;
};