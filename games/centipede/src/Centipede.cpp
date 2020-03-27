/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centipede
*/

#include "Centipede.hpp"

const std::vector<Entity *> &Centipede::getEntities()
{
    _entities.clear();
    _entities.push_back(new Entity(MAP, 30, 31));
    _entities.push_back(new Entity(SCORE, _scoreManager.getScore(), 0));
    if (_insectsManager.getCentiKill() == 20) {
        _entities.push_back(new Entity(GAME_WON, 5, 15));
    } else if (_playerGnome.isAlive() == false) {
        _entities.push_back(new Entity(GAME_LOST, 5, 15));
    } else {
        _entities.push_back(_playerGnome.getEntity());
        for (auto it : _mushroomManager.getMushroomsAsEntities())
            _entities.push_back(it);
        if (_shootManager.isActiveShoot() == true)
            _entities.push_back(_shootManager.getEntity());
        for (auto it : _insectsManager.getEntities())
            _entities.push_back(it);
    }
    return (_entities);
}

void Centipede::receiveEvent(Event event)
{
    switch (event) {
    case UP_KEY:
        _playerGnome.moveUp(_mushroomManager);
        break;
    case DOWN_KEY:
        _playerGnome.moveDown(_mushroomManager);
        break;
    case RIGHT_KEY:
        _playerGnome.moveRight(_mushroomManager);
        break;
    case LEFT_KEY:
        _playerGnome.moveLeft(_mushroomManager);
        break;
    case SPACE:
        if (_shootManager.isActiveShoot() == false)
            _shootManager.initShoot(_playerGnome.getPosX(), _playerGnome.getPosY());
        break;
    default:
        break;
    }
}

void Centipede::oneCycleLoop()
{
    if (_insectsManager.getCentiKill() == 20) {
        return;
    }
    if (_playerGnome.isAlive() == false) {
        return;
    }
    _shootManager.oneCycleLoop(_mushroomManager, _scoreManager, _insectsManager);
    if (_counter == 1) {
        _insectsManager.oneCycleLoop(_mushroomManager, _scoreManager);
        _counter = 0;
    }
    _playerGnome.setIsAlive(!_insectsManager.isCenti(_playerGnome.getPosX(), _playerGnome.getPosY()));
    _counter++;
}

void Centipede::initGame(const std::string &username)
{
    _playerName = username;
    _playerGnome.initGnome();
    _mushroomManager.initRandomMushrooms();
    _insectsManager.setCentiKill(0);
    _scoreManager.resetScore();
}

void Centipede::closeGame()
{
    _mushroomManager.deleteAllMushroom();
    _insectsManager.destroyAllInsects();
    _scoreManager.saveScore(_playerName);
    _scoreManager.resetScore();
}

Centipede::Centipede()
{
    _counter = 0;
}

Centipede::~Centipede()
{
}
