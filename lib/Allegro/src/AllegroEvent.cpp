/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroEvent
*/

#include "AllegroEvent.hpp"

namespace AllegroManager {
AllegroEvent::AllegroEvent() : _eventList(NULL)
{
}

void AllegroEvent::initEvents()
{
    _eventList = al_create_event_queue();
}

void AllegroEvent::addScreenEvents(ALLEGRO_DISPLAY *window)
{
    al_register_event_source(_eventList, al_get_display_event_source(window));
}

void AllegroEvent::addKeyboardEvents()
{
    al_install_keyboard();
    al_get_keyboard_event_source();
    al_register_event_source(_eventList, al_get_keyboard_event_source());
}
        
void AllegroEvent::destroyEvents()
{
    al_destroy_event_queue(_eventList);
}

bool AllegroEvent::getNextEvent(ALLEGRO_EVENT *eventCatch) const
{
    if (al_get_next_event(_eventList, eventCatch) == false)
        return false;
    return true;
}

AllegroEvent::~AllegroEvent()
{
}
}