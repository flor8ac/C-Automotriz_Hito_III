# ECUs_HitoIII
Automotive C++ course

Owner: Flor Ochoa

Goal of the project:
    Simulation of the Gateway ECU and Control ECU.

Arquitecture:
    Simulator -> Gateway -> Control -> Dashboard

// TODO: Add file structure

Vehicle Signals:
    - Velocity
    - RPM
    - Temperature
    - Battery Voltage
    - Oil Pressure

Ranges:
    - Velocity: 0 to 220 Km/H
    - RPM: 0 to 8000 rpm
    - Temperature: -20 to 130 centigrades
    - Battery Voltage: 10 to 15.5 Volts 
    - Oil Pressure: 0.5 a 6 bar

// TODO: Validation criteria
// TODO: Signal time validation

Control ECU States:
    - INIT
    - SELF_TEST
    - OPERATIONAL
    - DEGRADED
    - SAFE_STATE
    - SHUTDOWN

// TODO: STL used.

How to compile:
g++ -Wall -Wextra -pedantic -std=c++17 main.cpp src/*.cpp -Iinclude -o ecu_sim

How to run:
./ecu_sim
