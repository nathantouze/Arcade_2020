/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroEvent
*/

#ifndef ALLEGROEVENT_HPP_
#define ALLEGROEVENT_HPP_

#include "AllegroManager.hpp"

namespace AllegroManager {
class AllegroEvent {
    public:
        AllegroEvent();
        void initEvents();
        void addScreenEvents(ALLEGRO_DISPLAY *window);
        void addKeyboardEvents();
        void destroyEvents();
        bool getNextEvent(ALLEGRO_EVENT *eventCatch) const;
        ~AllegroEvent();

    protected:
    private:
        ALLEGRO_EVENT_QUEUE *_eventList;
};
}

#endif /* !ALLEGROEVENT_HPP_ */
