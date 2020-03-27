/*
** EPITECH PROJECT, 2020
** WirelessController
** File description:
** TimerFPS
*/

#include "TimerFPS.hpp"

TimerFPS::TimerFPS(unsigned int nbFPS) : _nbFPS(nbFPS), _start(std::chrono::system_clock::now())
{
}

#include <iostream>
bool TimerFPS::isTimerOkay()
{
    auto now = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = now - _start;

    if (elapsed_seconds >= (std::chrono::duration<int64_t, std::nano>)(1000000000 / _nbFPS)) {
        _start = now;
        return (true);
    }
    //std::cout << "false" << std::endl;
    return (false);
}

TimerFPS::~TimerFPS()
{
}
