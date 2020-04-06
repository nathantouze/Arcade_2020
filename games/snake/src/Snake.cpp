/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#include "Snake.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>

void Snake::winGame()
{
    _status = IN_PROGRESS;
}

void Snake::looseGame()
{
    _status = LOST;
}

int Snake::getScore() const
{
    return _score;
}

void Snake::closeGame()
{
    delete _map;
    delete _apple;
    _obstacles.clear();
    _snake.clear();
    _entities.clear();
    _current_event = NO_EVENT;
    _new_event = NO_EVENT;
    _status = CLOSED;
    _score = 0;
}

void Snake::initGame()
{
    int x = 0;
    int y = 0;

    _map = new Entity(MAP, 20, 20);
    _apple = new Entity(BONUS_1, 10, 3);
    _score = 0;
    for (int i = 0; i < 20; i++, x++) {
        _obstacles.push_back(new Entity(WALL_1, x, y));
    }
    x--;
    y = 1;
    for (int i = 0; i < 19; i++, y++)
        _obstacles.push_back(new Entity(WALL_1, x, y));
    x = 0;
    y = 1;
    for (int i = 0; i < 19; i++, y++)
        _obstacles.push_back(new Entity(WALL_1, x, y));
    y--;
    x = 1;
    for (int i = 0; i < 18; i++, x++)
        _obstacles.push_back(new Entity(WALL_1, x, y));
    _map = new Entity(MAP, 20, 20);
    _snake.push_back(new Entity(PLAYER_2, 10, 10));
    _snake.push_back(new Entity(PLAYER_3, 10, 9));
    _snake.push_back(new Entity(PLAYER_3, 10, 8));
    _snake.push_back(new Entity(PLAYER_4, 10, 7));
    std::srand(std::time(NULL));
    _current_event = DOWN_KEY;
    _new_event = DOWN_KEY;
    _loop_counter = 0;
    _difficulty = 5;
    _status = IN_PROGRESS;
}

bool Snake::checkEatItself()
{
    for (long unsigned int i = 0; i < _snake.size(); i++) {
        for (long unsigned int k = 0; k < _snake.size(); k++) {
            if (i != k && _snake.at(i)->getPosX() == _snake.at(k)->getPosX() && _snake.at(i)->getPosY() == _snake.at(k)->getPosY())
                return true;
        }
    }
    return false;
}

void Snake::grow_up(int x, int y)
{
    ApplePos pos = NOT_SET;
    int new_apple_x = 0;
    int new_apple_y = 0;

    _snake.at(_snake.size()-1)->setType(PLAYER_3);
    _snake.push_back(new Entity(PLAYER_4, x, y));
    while (pos == NOT_SET) {
        pos = SET;
        new_apple_x = rand() % 20;
        new_apple_y = rand() % 20;
        if (new_apple_x == 0 || new_apple_x == 19 || new_apple_y == 0 || new_apple_y == 19) {
            pos = NOT_SET;
            continue;
        }
        std::for_each(_snake.begin(), _snake.end(), [&new_apple_x, &new_apple_y, &pos] (IEntity *part) {
            if (part->getPosX() == new_apple_x && part->getPosY() == new_apple_y)
                pos = NOT_SET;
        });
        if (_snake.size() == 324) {
            winGame();
            pos = FINISHED;
        }
    }
    if (pos == SET) {
        _score += 50;
        _apple->updatePos(new_apple_x, new_apple_y);
    }
}

bool Snake::oneCycleLoop()
{
    if (_status == WON || _status == LOST) {}
    else if (_loop_counter == _difficulty) {
        int last_x = _snake.at(_snake.size() - 1)->getPosX();
        int last_y = _snake.at(_snake.size() - 1)->getPosY();

        for (int i = _snake.size() - 1; i != 0; i--)
            _snake.at(i)->updatePos(_snake.at(i - 1)->getPosX(), _snake.at(i - 1)->getPosY());
        if (_current_event == UP_KEY)
            _snake.at(0)->updatePos(_snake.at(0)->getPosX(), _snake.at(0)->getPosY() - 1);
        else if (_current_event == RIGHT_KEY)
            _snake.at(0)->updatePos(_snake.at(0)->getPosX() + 1, _snake.at(0)->getPosY());
        else if (_current_event == DOWN_KEY)
            _snake.at(0)->updatePos(_snake.at(0)->getPosX(), _snake.at(0)->getPosY() + 1);
        else if (_current_event == LEFT_KEY)
            _snake.at(0)->updatePos(_snake.at(0)->getPosX() - 1, _snake.at(0)->getPosY());
        if (_snake.at(0)->getPosX() == 19 || _snake.at(0)->getPosY() == 19 || _snake.at(0)->getPosX() == 0 || _snake.at(0)->getPosY() == 0 || checkEatItself() == true)
            looseGame();
        if (_snake.at(0)->getPosX() == _apple->getPosX() && _snake.at(0)->getPosY() == _apple->getPosY())
            grow_up(last_x, last_y);
        _loop_counter = 0;
    }  
    _loop_counter++;
    return true;
}

void Snake::receiveEvent(KeyBind event)
{
    if (event == LEFT_KEY || event == RIGHT_KEY || event == UP_KEY || event == DOWN_KEY) {
        if ((event == RIGHT_KEY && _current_event != LEFT_KEY) || (event == LEFT_KEY && _current_event != RIGHT_KEY) || \
(event == UP_KEY && _current_event != DOWN_KEY) || (event == DOWN_KEY && _current_event != UP_KEY))
             _current_event = event;
    }
}

const std::vector<IEntity *> &Snake::getEntities()
{
    _entities.clear();
    _entities.push_back(_map);
    std::for_each(_obstacles.begin(), _obstacles.end(), [this] (IEntity *obstacle) {
        _entities.push_back(obstacle);
    });
    _entities.push_back(_apple);
    std::for_each(_snake.begin(), _snake.end(), [this] (IEntity *snake_part) {
        _entities.push_back(snake_part);
    });
    if (_status == LOST)
        _entities.push_back(new Entity(GAME_LOST, 5, 5));
    else if (_status == WON)
        _entities.push_back(new Entity(GAME_WON, 5, 5));
    return _entities;
}

Snake::Snake()
{
}

Snake::~Snake()
{
}
