#include "ecugateway.h"

ECUGateway::ECUGateway() {}

void ECUGateway::addSensor(const Sensor& sensor) {
    sensors.push_back(sensor);
}

Sensor* ECUGateway::findSensor(const std::string& name) {
    // Using STL std::find_if
    auto it = std::find_if(sensors.begin(), sensors.end(), [&name](const Sensor& s) {
        return s.getName() == name;
    });
    if (it != sensors.end()) {
        return &(*it);
    }
    return nullptr;
}

std::vector<Sensor>& ECUGateway::getSensors() {
    return sensors;
}

const std::vector<Sensor>& ECUGateway::getSensors() const {
    return sensors;
}

int ECUGateway::countInvalidSensors() const {
    // Using STL std::count_if
    return std::count_if(sensors.begin(), sensors.end(), [](const Sensor& s) {
        return !s.isValid();
    });
}