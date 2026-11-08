#pragma once
#include <string>
#include <vector>
#include "sensor.h"

enum class ECUState {
    INIT,
    OPERATIONAL,
    DEGRADED,
    SAFE_STATE
};

std::string stateToString(ECUState state);

class ECUControl {
private:
    ECUState currentState;

public:
    ECUControl();
    ECUState evaluateState(const std::vector<Sensor>& sensors, int cycle);
    ECUState getCurrentState() const;
};