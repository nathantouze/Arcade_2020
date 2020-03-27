/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MenuArcade
*/

#ifndef MENUARCADE_HPP_
#define MENUARCADE_HPP_

#include "Event.hpp"
#include "MenuInfo.hpp"
#include "ILibIO.hpp"
#include "ILibGame.hpp"
#include "ScoreModule/ScoreModule.hpp"

class MenuArcade {
    public:
        MenuArcade();
        void launchMenu();
        void eventListener(Event event);
        void loadMenu();
        const MenuInfo &getMenuInfos() const;
        ILibGame *getActualGame();
        ILibIO *getActualGraphLib();
        ~MenuArcade();

    protected:
    private:
        void setIdx();
        void setPlayerName(Event event);
        MenuInfo _menuInfos;
        std::vector<DLLoader<ILibIO>*> _libVector;
        std::vector<DLLoader<ILibGame>*> _gameVector;
};

#endif /* !MENUARCADE_HPP_ */
