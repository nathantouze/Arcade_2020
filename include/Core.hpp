/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "MenuArcade.hpp"

class Core {
    public:
        Core(IDisplayModule *libGraphical);
        void launchMenu();
        void launchGame();
        void loopCore();
        ~Core();

    protected:
    private:
        IDisplayModule *_graphicalLib;
        IGameModule *_gameLib;
        MenuArcade _menuArcade;
        bool _isMenuActive;
        bool manageEventOnCore(KeyBind event);
        void closeCore();
        void oneLoop();
        void restartGame();
        void launchPrevGame();
        void launchNextGame();
        void launchPrevLib();
        void launchNextLib();
};

#endif /* !CORE_HPP_ */
