/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MushroomManager
*/

#ifndef MUSHROOMMANAGER_HPP_
#define MUSHROOMMANAGER_HPP_

#include "Mushroom.hpp"
#include "ScoreManager.hpp"
#include <vector>

class MushroomManager {
    public:
        MushroomManager();
        void initRandomMushrooms();
        void resetActualMushrooms(ScoreManager &scoreManager);
        bool isMushroom(int posX, int posY) const;
        void addMushroom(int posX, int posY);
        void hitMushroom(int posX, int posY, ScoreManager &scoreManager);
        void deleteAllMushroom();
        std::vector<Entity *> getMushroomsAsEntities() const;
        ~MushroomManager();

    protected:
    private:
        std::vector<Mushroom *> _mushrooms;
};

#endif /* !MUSHROOMMANAGER_HPP_ */
