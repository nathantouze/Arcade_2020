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
#include "IDisplayModule.hpp"
#include "TypeEntity.hpp"
#include "KeyBind.hpp"
#include "Entity.hpp"

#define PADDING_HEIGHT _maxheight / 6
#define PADDING_WIDTH _maxwidth / 2.5

class NcurseLib: public IDisplayModule {
	public:
		NcurseLib();
		~NcurseLib();
        bool isOpen() const;
        void drawEntity(const IEntity &ent_1);
        KeyBind eventListener();
        void oneCycleDisplay();
        void displayMenu(const MenuInfo &menuInfo);
        void oneCycleClear();
        void initWindow();
        void destroyWindow();
        int getmaxheight() const;
        int getmaxwidth() const;
    private:
        void drawLetter(const IEntity &_entity, const std::string &letter) const;
        void drawGameWon() const;
        void drawGameLost() const;
        void drawError(const IEntity &_entity) const;
        void drawScore(const IEntity &_entity) const;
        int _maxwidth;
        int _maxheight;
        bool _open;
};

// extern "C" {
//     IDisplayModule *entryPoint() {
//         return (new NcurseLib());
//     }
// }

#endif /* !NCURSESCLASS_HPP_ */