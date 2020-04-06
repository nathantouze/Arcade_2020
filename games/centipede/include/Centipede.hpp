/*
** EPITECH PROJECT, 2020
** centipede
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "IGameModule.hpp"
#include "Gnome.hpp"
#include "MushroomManager.hpp"
#include "ShootManager.hpp"
#include "insects/InsectsManager.hpp"

class Centipede : public IGameModule {
    public:
        Centipede();
        ~Centipede();
        const std::vector<IEntity *> &getEntities();
        void receiveEvent(KeyBind event);
        bool oneCycleLoop();
        void initGame();
        int getScore() const;
        void closeGame();

    protected:
    private:
        Gnome _playerGnome;
        std::vector<IEntity *> _entities;
        MushroomManager _mushroomManager;
        ScoreManager _scoreManager;
        ShootManager _shootManager;
        InsectsManager _insectsManager;
        int _counter;
};

extern "C" {
    IGameModule *entryPoint() {
        return (new Centipede());
    }
}

#endif /* !CENTIPEDE_HPP_ */
