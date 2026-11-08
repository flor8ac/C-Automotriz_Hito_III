#include <iostream>
#include <thread>
#include <chrono>
#include "include/sensor.h"
#include "include/vehiclesimulator.h"
#include "include/ecugateway.h"
#include "include/ecucontrol.h"
#include "include/dashboard.h"

int main() {
    ECUGateway gateway;
    gateway.addSensor(Sensor("Velocity", "km/h", 0.0, 220.0, 3));
    gateway.addSensor(Sensor("RPM", "rpm", 0.0, 8000.0, 3));
    gateway.addSensor(Sensor("Temperature", "°C", -20.0, 130.0, 3));
    gateway.addSensor(Sensor("Battery Voltage", "V", 10.0, 15.5, 3));
    gateway.addSensor(Sensor("Oil Pressure", "bar", 0.5, 6.0, 3));

    VehicleSimulator simulator(12345);
    ECUControl ecuControl;
    Dashboard dashboard;

    int cycle = 0;

    while (true) {
        cycle++;

        // 1. Simulate vehicle / update raw data
        simulator.simulateVehicle(gateway.getSensors(), cycle);

        // 2. Gateway processes and validates sensors automatically via methods

        // 3. ECU Control evaluates processed signals and runs FSM
        ECUState state = ecuControl.evaluateState(gateway.getSensors(), cycle);

        // 4. Dashboard renders results
        dashboard.render(gateway.getSensors(), state, cycle);

        // 5. Sleep for 1 second per cycle
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}