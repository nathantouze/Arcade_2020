/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** InsectsManager
*/

#ifndef INSECTSMANAGER_HPP_
#define INSECTSMANAGER_HPP_

#include "insects/CentiManager.hpp"
#include "insects/Slug.hpp"
#include "insects/Smurf.hpp"
#include "insects/Spider.hpp"

class InsectsManager {
    public:
        InsectsManager();
        void oneCycleLoop(MushroomManager &mushroomManager, ScoreManager &scoreManager);
        bool isCenti(int posX, int posY) const;
        void hitCenti(int posX, int posY, ScoreManager &scoreManager);
        int getCentiKill() const;
        void setCentiKill(int centiKill);
        void destroyAllInsects();
        std::vector<Entity *> getEntities() const;
        ~InsectsManager();

    protected:
    private:
        CentiManager _centiManager;
        int _centiKill;
};

#endif /* !INSECTSMANAGER_HPP_ */
