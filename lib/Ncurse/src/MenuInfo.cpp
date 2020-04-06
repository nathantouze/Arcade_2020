/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by jserenne,
*/
#include "MenuInfo.hpp"

/* Constructor */

MenuInfo::MenuInfo() : _graphIdx(0), _gameIdx(0), _activeBoxIdx(0)
{}

/* Destructor */

MenuInfo::~MenuInfo()
= default;

/* Getter */

const std::vector<std::string> &MenuInfo::getGraphList() const
{
    return _graphList;
}

const std::vector<std::string> &MenuInfo::getGameList() const
{
    return _gameList;
}

const std::vector<std::pair<std::string, std::string>> &MenuInfo::getGameScores() const
{
    return _gameScores;
}

const int &MenuInfo::getGraphIdx() const
{
    return _graphIdx;
}

const int &MenuInfo::getGameIdx() const
{
    return _gameIdx;
}

const int &MenuInfo::getActiveBoxIdx() const
{
    return _activeBoxIdx;
}

const std::string &MenuInfo::getPlayerName() const
{
    return _playerName;
}

/* Setter */

void MenuInfo::setGraphList(std::vector<std::string> graphList)
{
    _graphList = std::move(graphList);
}

void MenuInfo::setGameList(std::vector<std::string> gameList)
{
    _gameList = std::move(gameList);
}

void MenuInfo::setGameScores(std::vector<std::pair<std::string, std::string>> gameScores)
{
    _gameScores = std::move(gameScores);
}

void MenuInfo::setGraphIdx(int graphIdx)
{
    _graphIdx = graphIdx;
}

void MenuInfo::setGameIdx(int gameIdx)
{
    _gameIdx = gameIdx;
}

void MenuInfo::setActiveBoxIdx(int activeBoxIdx)
{
    _activeBoxIdx = activeBoxIdx;
}

void MenuInfo::setPlayerName(const std::string &playerName)
{
    _playerName = playerName;
}
