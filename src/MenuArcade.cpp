/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MenuArcade
*/

#include "MenuArcade.hpp"
#include "DirectoryReader.hpp"
#include <cstring>
#include <iostream>

MenuArcade::MenuArcade()
{
    _score = 0;
    loadMenu();
}

MenuArcade::~MenuArcade()
{
}

void MenuArcade::launchMenu()
{
    for (auto it : _menuInfos.getGraphList()) {
        DLLoader<IDisplayModule> *loadLib = new DLLoader<IDisplayModule>("./lib/" + it);
        _libVector.push_back(loadLib);
    }
    for (auto it : _menuInfos.getGameList()) {
        DLLoader<IGameModule> *loadGame = new DLLoader<IGameModule>("./games/" + it);
        _gameVector.push_back(loadGame);
    }
}

IGameModule *MenuArcade::getActualGame()
{
    return (_gameVector[_menuInfos.getGameIdx()]->getInstance("entryPoint"));
}

IDisplayModule *MenuArcade::getActualGraphLib()
{
    return (_libVector[_menuInfos.getGraphIdx()]->getInstance("entryPoint"));
}

void MenuArcade::eventListener(KeyBind event)
{
    switch (event) {
    case RIGHT_KEY:
        if (_menuInfos.getActiveBoxIdx() >= 3)
            _menuInfos.setActiveBoxIdx(0);
        else
            _menuInfos.setActiveBoxIdx(_menuInfos.getActiveBoxIdx() + 1);
        break;

    case LEFT_KEY:
        if (_menuInfos.getActiveBoxIdx() <= 0)
            _menuInfos.setActiveBoxIdx(3);
        else
            _menuInfos.setActiveBoxIdx(_menuInfos.getActiveBoxIdx() - 1);
        break;

    case UP_KEY:
        if (_menuInfos.getActiveBoxIdx() == 0) {
            if (_menuInfos.getGraphIdx() <= 0)
                _menuInfos.setGraphIdx(_menuInfos.getGraphList().size() - 1);
            else
                _menuInfos.setGraphIdx(_menuInfos.getGraphIdx() - 1);
        }
        if (_menuInfos.getActiveBoxIdx() == 1) {
            if (_menuInfos.getGameIdx() <= 0)
                _menuInfos.setGameIdx(_menuInfos.getGameList().size() - 1);
            else
                _menuInfos.setGameIdx(_menuInfos.getGameIdx() - 1);
        }
        break;

    case DOWN_KEY:
        if (_menuInfos.getActiveBoxIdx() == 0) {
            if ((long unsigned int)(_menuInfos.getGraphIdx()) >= _menuInfos.getGraphList().size() - 1)
                _menuInfos.setGraphIdx(0);
            else
                _menuInfos.setGraphIdx(_menuInfos.getGraphIdx() + 1);
        }
        if (_menuInfos.getActiveBoxIdx() == 1) {
            if ((long unsigned int)(_menuInfos.getGameIdx()) >= _menuInfos.getGameList().size() - 1)
                _menuInfos.setGameIdx(0);
            else
                _menuInfos.setGameIdx(_menuInfos.getGameIdx() + 1);
        }
        break;

    default:
        setPlayerName(event);
        break;
    }
    setIdx();
}

void MenuArcade::setPlayerName(KeyBind event)
{
    if (event == RETURN) {
        _menuInfos.setPlayerName(_menuInfos.getPlayerName().substr(0, _menuInfos.getPlayerName().size() - 1));
        return;
    }
    if (_menuInfos.getPlayerName().size() == 10)
        return;
    switch (event) {
        case A:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'a');
            break;
        case B:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'b');
            break;
        case C:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'c');
            break;
        case D:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'd');
            break;
        case E:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'e');
            break;
        case F:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'f');
            break;
        case G:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'g');
            break;
        case H:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'h');
            break;
        case I:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'i');
            break;
        case J:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'j');
            break;
        case K:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'k');
            break;
        case L:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'l');
            break;
        case M:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'm');
            break;
        case N:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'n');
            break;
        case O:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'o');
            break;
        case P:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'p');
            break;
        case Q:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'q');
            break;
        case R:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'r');
            break;
        case S:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 's');
            break;
        case T:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 't');
            break;
        case U:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'u');
            break;
        case V:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'v');
            break;
        case W:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'w');
            break;
        case X:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'x');
            break;
        case Y:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'y');
            break;
        case Z:
            _menuInfos.setPlayerName(_menuInfos.getPlayerName() + 'z');
            break;
        default:
            break;
    }
}
    
const MenuInfo &MenuArcade::getMenuInfos() const
{
    return _menuInfos;
}

void MenuArcade::saveScore()
{
    ScoreModule::encryptScore(_menuInfos.getGameList().at(_menuInfos.getGameIdx()), _menuInfos.getPlayerName(), _score);
    _score = 0;
}

void MenuArcade::setScore(int score)
{
    _score = score;
}

void MenuArcade::setIdx()
{
    if ((long unsigned int)(_menuInfos.getGameIdx()) >= _menuInfos.getGameList().size())
        _menuInfos.setGameIdx(_menuInfos.getGameList().size() - 1);
    if ((long unsigned int)(_menuInfos.getGraphIdx()) >= _menuInfos.getGraphList().size())
        _menuInfos.setGraphIdx(_menuInfos.getGraphList().size() - 1);
    if (_menuInfos.getGameList().size() > 0)
        _menuInfos.setGameScores(ScoreModule::getScoreOfGame(_menuInfos.getGameList().at(_menuInfos.getGameIdx())));
}

void MenuArcade::loadMenu()
{
    DirectoryReader lib("./lib");
    DirectoryReader games("./games");

    if (lib.isDirectoryExists() == true) {
        lib.reloadList();
        std::vector<std::string> list;
        for (auto it : lib.getList()) {
            if (it.substr(0, 11).compare("lib_arcade_") == 0 && it.substr(it.size() - 3, it.size()).compare(".so") == 0)
                list.push_back(it);
        }
        _menuInfos.setGraphList(list);
    }
    if (games.isDirectoryExists() == true) {
        games.reloadList();
        std::vector<std::string> list;
        for (auto it : games.getList()) {
            if (it.substr(0, 11).compare("lib_arcade_") == 0 && it.substr(it.size() - 3, it.size()).compare(".so") == 0)
                list.push_back(it);
        }
        _menuInfos.setGameList(list);
    }
    setIdx();
}