/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoreManager
*/

#include "ScoreManager.hpp"
#include "ScoreModule/ScoreModule.hpp"

ScoreManager::ScoreManager()
{
}

void ScoreManager::saveScore(const std::string &playerName) const
{
    ScoreModule::encryptScore("lib_arcade_centipede.so", playerName, _score);
}

void ScoreManager::resetScore()
{
    _score = 0;
}

void ScoreManager::breakMushroom()
{
    _score += 1;
}

void ScoreManager::resetMushroom()
{
    _score += 5;
}

void ScoreManager::breakSpider()
{
    _score += 600;
}

void ScoreManager::breakCentipede()
{
    _score += 100;
}

void ScoreManager::centiOnBot()
{
    _score -= 10;
}

int ScoreManager::getScore() const
{
    return _score;
}

ScoreManager::~ScoreManager()
{
}
