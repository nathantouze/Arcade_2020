/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CentiManager
*/

#ifndef CENTIMANAGER_HPP_
#define CENTIMANAGER_HPP_

#include "insects/Centi.hpp"

class CentiManager {
    public:
        CentiManager();
        void releaseNewCenti();
        bool isCentiOnMap() const;
        bool isCenti(int posX, int posY) const;
        void oneCycleLoop(MushroomManager &mushroomManager, ScoreManager &scoreManager);
        void hitCenti(int posX, int posY, ScoreManager &scoreManager);
        std::vector<Entity *> getEntities() const;
        void destroyAllCenti();
        ~CentiManager();

    protected:
    private:
        void eraseEmptyCenti();
        std::vector<Centi *> _centiList;
};

#endif /* !CENTIMANAGER_HPP_ */
