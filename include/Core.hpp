/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include "ILibIO.hpp"
#include "ILibGame.hpp"
#include "MenuArcade.hpp"

class Core {
    public:
        Core(ILibIO *libGraphical);
        void launchMenu();
        void launchGame();
        void loopCore();
        ~Core();

    protected:
    private:
        ILibIO *_graphicalLib;
        ILibGame *_gameLib;
        MenuArcade _menuArcade;
        bool _isMenuActive;
        bool manageEventOnCore(Event event);
        void closeCore();
        void oneLoop();
        void restartGame();
        void launchPrevGame();
        void launchNextGame();
        void launchPrevLib();
        void launchNextLib();
};

#endif /* !CORE_HPP_ */
