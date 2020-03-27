/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ShootManager
*/

#ifndef SHOOTMANAGER_HPP_
#define SHOOTMANAGER_HPP_

#include "Entity.hpp"
#include "MushroomManager.hpp"
#include "insects/InsectsManager.hpp"

class ShootManager : public Entity {
    public:
        ShootManager();
        ~ShootManager();
        bool isActiveShoot() const;
        void initShoot(int x, int y);
        void oneCycleLoop(MushroomManager &mushroomManager, ScoreManager &scoreManager, InsectsManager &insectsManager);
        Entity *getEntity() const;

    protected:
    private:
        bool _active;
};

#endif /* !SHOOTMANAGER_HPP_ */
