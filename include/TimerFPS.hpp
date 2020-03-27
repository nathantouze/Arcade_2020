/*
** EPITECH PROJECT, 2020
** WirelessController
** File description:
** TimerFPS
*/

#ifndef TIMERFPS_HPP_
#define TIMERFPS_HPP_
#include <chrono>

class TimerFPS {
    public:
        TimerFPS(unsigned int nbFPS);
        bool isTimerOkay();
        ~TimerFPS();

    protected:
    private:
        unsigned int _nbFPS;
        std::chrono::time_point<std::chrono::system_clock> _start;
};

#endif /* !TIMERFPS_HPP_ */
