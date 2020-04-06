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

Core::Core(IDisplayModule *libGraphical) : _graphicalLib(libGraphical), _gameLib(nullptr)
{
    _isMenuActive = true;
    _menuArcade.launchMenu();
}

Core::~Core()
{
}

void Core::launchMenu()
{
    if (_isMenuActive == false) {
        _menuArcade.saveScore();
        _gameLib->closeGame();
    }
    _isMenuActive = true;
} 

void Core::launchPrevGame()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 1)
        _menuArcade.eventListener(KeyBind::RIGHT_KEY);
    _menuArcade.eventListener(KeyBind::UP_KEY);
    _gameLib->closeGame();
    _menuArcade.saveScore();
    _gameLib = _menuArcade.getActualGame();
    _gameLib->initGame();
}

void Core::launchNextGame()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 1)
        _menuArcade.eventListener(KeyBind::RIGHT_KEY);
    _menuArcade.eventListener(KeyBind::DOWN_KEY);
    _gameLib->closeGame();
    _menuArcade.saveScore();
    _gameLib = _menuArcade.getActualGame();
    _gameLib->initGame();
}

void Core::launchPrevLib()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 0)
        _menuArcade.eventListener(KeyBind::RIGHT_KEY);
    _menuArcade.eventListener(KeyBind::UP_KEY);
    _graphicalLib->destroyWindow();
    _graphicalLib = _menuArcade.getActualGraphLib();
    _graphicalLib->initWindow();
}

void Core::launchNextLib()
{
    while (_menuArcade.getMenuInfos().getActiveBoxIdx() != 0)
        _menuArcade.eventListener(KeyBind::RIGHT_KEY);
    _menuArcade.eventListener(KeyBind::DOWN_KEY);
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
        _gameLib->initGame();
    }
}

void Core::restartGame()
{
    _gameLib->closeGame();
    _menuArcade.saveScore();
    _gameLib->initGame();
}

void Core::oneLoop()
{
    KeyBind event = _graphicalLib->eventListener();
    if (manageEventOnCore(event) == false) {
        if (_isMenuActive == true)
            _menuArcade.eventListener(event);
        else
            _gameLib->receiveEvent(event);
    }
    if (_graphicalLib->isOpen() == false)
        return;
    _graphicalLib->oneCycleClear();
    if (_isMenuActive == true) {
        _graphicalLib->displayMenu(_menuArcade.getMenuInfos());
    } else {
        _gameLib->oneCycleLoop();
        std::vector<IEntity *> entities = _gameLib->getEntities();
        _menuArcade.setScore(_gameLib->getScore());
        for (auto it : entities)
            _graphicalLib->drawEntity(*it);
    }
    _graphicalLib->oneCycleDisplay();
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
        std::cerr << e.what() << std::endl;
    }
}

bool Core::manageEventOnCore(KeyBind event)
{
    if (event == ARROWDOWN)
        event = DOWN_KEY;
    if (event == ARROWLEFT)
        event = LEFT_KEY;
    if (event == ARROWRIGHT)
        event = RIGHT_KEY;
    if (event == ARROWUP)
        event = UP_KEY;
    if (event == F1)
        event = PREV_LIB;
    if (event == F2)
        event = NEXT_LIB;
    if (event == F3)
        event = PREV_GAME;
    if (event == F4)
        event = NEXT_GAME;
    if (event == F5)
        event = RESTART;
    if (event == F6)
        event = MENU;
    if (event == ENTER)
        event = VALID;
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