/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NCURSESclass
*/

#ifndef NCURSESCLASS_HPP_
#define NCURSESCLASS_HPP_

#include <ncurses.h>
#include <chrono>
#include <list>
#include <vector>
#include <algorithm>
#include <thread>
#include <unordered_map>
#include <iostream>
#include "ILibIO.hpp"
#include "TypeEntity.hpp"
#include "Event.hpp"
#include "Entity.hpp"

#define PADDING_HEIGHT _maxheight / 6
#define PADDING_WIDTH _maxwidth / 2.5

class NcurseLib: public ILibIO {
	public:
		NcurseLib();
		~NcurseLib();
        void initWindow();
        void display() const;
        void drawEntity(const IEntity &entity);
        void displayMenu(const MenuInfo &menu);
        Event eventListener() const;
        void clearWindow();
        void destroyWindow();
        bool isOpen() const;
        int getmaxheight() const;
        int getmaxwidth() const;
    private:
        void drawPlayer(const IEntity &_entity) const;
        void drawEnemy(const IEntity &_entity) const;
        void drawWall(const IEntity &_entity) const;
        void drawMap(const IEntity &_entity) const;
        void drawGnome(const IEntity &_entity) const;
        void drawShoot(const IEntity &_entity) const;
        void drawMushroom(const IEntity &_entity) const;
        void drawSnakeHead(const IEntity &_entity) const;
        void drawSnakeBody(const IEntity &_entity) const;
        void drawSnakeTail(const IEntity &_entity) const;
        void drawFloor(const IEntity &_entity) const;
        void drawBonus(const IEntity &_entity) const;
        void drawGameWon() const;
        void drawGameLost() const;
        void drawError(const IEntity &_entity) const;
        void drawScore(const IEntity &_entity) const;
        int _maxwidth;
        int _maxheight;
        bool _open;
};

extern "C" {
    ILibIO *entryPoint() {
        return (new NcurseLib());
    }
}

#endif /* !NCURSESCLASS_HPP_ */