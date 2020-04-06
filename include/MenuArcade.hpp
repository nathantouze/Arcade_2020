/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MenuArcade
*/

#ifndef MENUARCADE_HPP_
#define MENUARCADE_HPP_

#include "KeyBind.hpp"
#include "MenuInfo.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include "DLLoader.hpp"
#include "DLLoaderException.hpp"
#include "ScoreModule/ScoreModule.hpp"

class MenuArcade {
    public:
        MenuArcade();
        void launchMenu();
        void eventListener(KeyBind event);
        void loadMenu();
        const MenuInfo &getMenuInfos() const;
        IGameModule *getActualGame();
        IDisplayModule *getActualGraphLib();
        void saveScore();
        void setScore(int score);
        ~MenuArcade();

    protected:
    private:
        int _score;
        void setIdx();
        void setPlayerName(KeyBind event);
        MenuInfo _menuInfos;
        std::vector<DLLoader<IDisplayModule>*> _libVector;
        std::vector<DLLoader<IGameModule>*> _gameVector;
};

#endif /* !MENUARCADE_HPP_ */
