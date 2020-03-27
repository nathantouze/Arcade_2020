/*
** EPITECH PROJECT, 2020
** centipede
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "ILibGame.hpp"
#include "Gnome.hpp"
#include "MushroomManager.hpp"
#include "ShootManager.hpp"
#include "insects/InsectsManager.hpp"

class Centipede : public ILibGame {
    public:
        Centipede();
        ~Centipede();
        const std::vector<Entity *> &getEntities();
        void receiveEvent(Event event);
        void oneCycleLoop();
        void initGame(const std::string &username);
        void closeGame();

    protected:
    private:
        std::string _playerName;
        Gnome _playerGnome;
        std::vector<Entity *> _entities;
        MushroomManager _mushroomManager;
        ScoreManager _scoreManager;
        ShootManager _shootManager;
        InsectsManager _insectsManager;
        int _counter;
};

extern "C" {
    ILibGame *entryPoint() {
        return (new Centipede());
    }
}

#endif /* !CENTIPEDE_HPP_ */
