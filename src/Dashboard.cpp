#include "dashboard.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Dashboard::Dashboard() {}

void Dashboard::render(const std::vector<Sensor>& sensors, ECUState controlState, int cycle) const {
    system("clear");
    std::cout << "=============================================================\n";
    std::cout << "               ECU GATEWAY / CONTROL DASHBOARD               \n";
    std::cout << "=============================================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "SIGNAL                VALUE        STATUS         UNUPDATED CYCLES\n";
    std::cout << "-------------------------------------------------------------\n";

    for (const auto& s : sensors) {
        std::cout << std::left << std::setw(20) << s.getName() 
                  << std::setw(6) << s.getValue() << " " << std::setw(5) << s.getUnit() 
                  << " -  " << std::setw(10) << (s.isValid() ? "VALID" : "INVALID") 
                  << " -    " << s.getUnupdatedCycles() << "\n";
    }

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "ECU CONTROL STATUS : " << stateToString(controlState) << "\n";
    std::cout << "CURRENT CYCLE      : " << cycle << "\n";
    std::cout << "=============================================================\n";
}