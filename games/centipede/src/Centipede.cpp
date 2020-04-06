/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centipede
*/

#include "Centipede.hpp"

int Centipede::getScore() const
{
    return _scoreManager.getScore();
}

const std::vector<IEntity *> &Centipede::getEntities()
{
    _entities.clear();
    _entities.push_back(new Entity(MAP, 30, 31));
    if (_insectsManager.getCentiKill() == 20) {
        _entities.push_back(new Entity(GAME_WON, 10, 15));
    } else if (_playerGnome.isAlive() == false) {
        _entities.push_back(new Entity(GAME_LOST, 10, 15));
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

void Centipede::receiveEvent(KeyBind event)
{
    switch (event) {
    case UP_KEY:
        _playerGnome.moveUp(_mushroomManager);
        break;
    case ARROWUP:
        _playerGnome.moveUp(_mushroomManager);
        break;
    case RIGHT_KEY:
        _playerGnome.moveRight(_mushroomManager);
        break;
    case ARROWRIGHT:
        _playerGnome.moveRight(_mushroomManager);
        break;
    case DOWN_KEY:
        _playerGnome.moveDown(_mushroomManager);
        break;
    case ARROWDOWN:
        _playerGnome.moveDown(_mushroomManager);
        break;
    case LEFT_KEY:
        _playerGnome.moveLeft(_mushroomManager);
        break;
    case ARROWLEFT:
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

bool Centipede::oneCycleLoop()
{
    int difficulty = 3;
    if (_insectsManager.getCentiKill() == 20)
        return true;
    if (_playerGnome.isAlive() == false)
        return true;
    if (_insectsManager.getCentiKill() > 5 && _insectsManager.getCentiKill() <= 10)
        difficulty = 2;
    else if (_insectsManager.getCentiKill() > 10)
        difficulty = 1;
    _shootManager.oneCycleLoop(_mushroomManager, _scoreManager, _insectsManager);
    if (_counter == difficulty) {
        _insectsManager.oneCycleLoop(_mushroomManager, _scoreManager);
        _counter = 0;
    }
    _playerGnome.setIsAlive(!_insectsManager.isCenti(_playerGnome.getPosX(), _playerGnome.getPosY()));
    _counter++;
    return true;
}

void Centipede::initGame()
{
    _playerGnome.initGnome();
    _mushroomManager.initRandomMushrooms();
    _insectsManager.setCentiKill(0);
    _scoreManager.resetScore();
}

void Centipede::closeGame()
{
    _mushroomManager.deleteAllMushroom();
    _insectsManager.destroyAllInsects();
    _scoreManager.resetScore();
}

Centipede::Centipede()
{
    _counter = 0;
}

Centipede::~Centipede()
{
}
