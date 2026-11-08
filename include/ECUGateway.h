#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "sensor.h"

class ECUGateway {
private:
    std::vector<Sensor> sensors;

public:
    ECUGateway();
    
    void addSensor(const Sensor& sensor);
    Sensor* findSensor(const std::string& name);
    std::vector<Sensor>& getSensors();
    const std::vector<Sensor>& getSensors() const;
    int countInvalidSensors() const;
};