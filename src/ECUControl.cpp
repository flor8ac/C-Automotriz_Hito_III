#include "ecucontrol.h"
#include <algorithm>

std::string stateToString(ECUState state) {
    switch (state) {
        case ECUState::INIT: return "INIT";
        case ECUState::OPERATIONAL: return "OPERATIONAL";
        case ECUState::DEGRADED: return "DEGRADED";
        case ECUState::SAFE_STATE: return "SAFE_STATE";
    }
    return "UNKNOWN";
}

ECUControl::ECUControl() : currentState(ECUState::INIT) {}

ECUState ECUControl::evaluateState(const std::vector<Sensor>& sensors, int cycle) {
    if (cycle == 1) {
        currentState = ECUState::INIT;
        return currentState;
    }
    if (cycle == 2) {
        currentState = ECUState::OPERATIONAL;
        return currentState;
    }

    int invalidCount = std::count_if(sensors.begin(), sensors.end(), [](const Sensor& s) {
        return !s.isValid();
    });

    auto itTemp = std::find_if(sensors.begin(), sensors.end(), [](const Sensor& s) {
        return s.getName() == "Temperature";
    });

    bool criticalTemperature = (itTemp != sensors.end() && (!itTemp->isValid() || itTemp->getValue() > 125.0));

    if (criticalTemperature) {
        currentState = ECUState::SAFE_STATE;
    } else if (invalidCount > 0) {
        currentState = ECUState::DEGRADED;
    } else {
        currentState = ECUState::OPERATIONAL;
    }

    return currentState;
}

ECUState ECUControl::getCurrentState() const {
    return currentState;
}