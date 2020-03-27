/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Entity.hpp"
#include "Core.hpp"
#include "MenuArcade.hpp"
#include "MenuInfo.hpp"
#include "DLLoader.hpp"
#include "TimerFPS.hpp"
#include <iostream>

Core::Core(ILibIO *libGraphical) : _graphicalLib(libGraphical), _gameLib(nullptr)
{
    _isMenuActive = true;
    _menuArcade.launchMenu();
}

Core::~Core()
{
}

void Core::launchMenu()
{
    if (_isMenuActive == false)
        _gameLib->closeGame();
    _isMenuActive = true;
} 

void Core::launchPrevGame()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 1)
        _menuArcade.eventListener(Event::RIGHT_KEY);
    _menuArcade.eventListener(Event::UP_KEY);
    _gameLib->closeGame();
    _gameLib = _menuArcade.getActualGame();
    _gameLib->initGame(_menuArcade.getMenuInfos().getPlayerName());
}

void Core::launchNextGame()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 1)
        _menuArcade.eventListener(Event::RIGHT_KEY);
    _menuArcade.eventListener(Event::DOWN_KEY);
    _gameLib->closeGame();
    _gameLib = _menuArcade.getActualGame();
    _gameLib->initGame(_menuArcade.getMenuInfos().getPlayerName());
}

void Core::launchPrevLib()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 0)
        _menuArcade.eventListener(Event::RIGHT_KEY);
    _menuArcade.eventListener(Event::UP_KEY);
    _graphicalLib->destroyWindow();
    _graphicalLib = _menuArcade.getActualGraphLib();
    _graphicalLib->initWindow();
}

void Core::launchNextLib()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 0)
        _menuArcade.eventListener(Event::RIGHT_KEY);
    _menuArcade.eventListener(Event::DOWN_KEY);
    _graphicalLib->destroyWindow();
    _graphicalLib = _menuArcade.getActualGraphLib();
    _graphicalLib->initWindow();
}

void Core::launchGame()
{
    MenuInfo menuInfo = _menuArcade.getMenuInfos();

    if (menuInfo.getActiveBoxIdx() == 3) {
        if (_menuArcade.getActualGraphLib() != _graphicalLib) {
            _graphicalLib->destroyWindow();
            _graphicalLib = _menuArcade.getActualGraphLib();
            _graphicalLib->initWindow();
        }
        _isMenuActive = false;
        _gameLib = _menuArcade.getActualGame();
        _gameLib->initGame(menuInfo.getPlayerName());
    }
}

void Core::restartGame()
{
    _gameLib->closeGame();
    _gameLib->initGame(_menuArcade.getMenuInfos().getPlayerName());
}

void Core::oneLoop()
{
    Event event = _graphicalLib->eventListener();
    if (manageEventOnCore(event) == false) {
        if (_isMenuActive == true)
            _menuArcade.eventListener(event);
        else
            _gameLib->receiveEvent(event);
    }
    if (_graphicalLib->isOpen() == false)
        return;
    _graphicalLib->clearWindow();
    if (_isMenuActive == true) {
        _graphicalLib->displayMenu(_menuArcade.getMenuInfos());
    } else {
        _gameLib->oneCycleLoop();
        std::vector<Entity *> entities = _gameLib->getEntities();
        for (auto it : entities)
            _graphicalLib->drawEntity(*it);
    }
    _graphicalLib->display();
}

void Core::loopCore()
{
    try {
        TimerFPS timer(20);
        _graphicalLib->initWindow();
        while (_graphicalLib->isOpen())
            if (timer.isTimerOkay()) {
                oneLoop();
            }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

bool Core::manageEventOnCore(Event event)
{
    if (_isMenuActive == true) {
        switch (event) {
        case NO_EVENT:
            break;
        case EXIT:
            closeCore();
            break;
        case VALID:
            launchGame();
            break;
        case PREV_LIB:
            launchPrevLib();
            break;
        case NEXT_LIB:
            launchNextLib();
            break;
        default:
            return (false);
            break;
        }
    } else {
        switch (event) {
        case NO_EVENT:
            break;
        case EXIT:
            closeCore();
            break;
        case PREV_GAME:
            launchPrevGame();
            break;
        case NEXT_GAME:
            launchNextGame();
            break;
        case PREV_LIB:
            launchPrevLib();
            break;
        case NEXT_LIB:
            launchNextLib();
            break;
        case RESTART:
            restartGame();
            break;
        case MENU:
            launchMenu();
            break;
        default:
            return (false);
            break;
        }
    }
    return (true);
}

void Core::closeCore()
{
    if (_isMenuActive == false)
        _gameLib->closeGame();
    _graphicalLib->destroyWindow();
}