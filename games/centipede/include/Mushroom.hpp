/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mushroom
*/

#ifndef MUSHROOM_HPP_
#define MUSHROOM_HPP_

#include "Entity.hpp"

class Mushroom : public Entity {
    public:
        Mushroom(int posX, int posY);
        ~Mushroom();
        Entity *getEntity();
        int getLives() const;
        void setLives(int lives);

    protected:
    private:
        int _lives;
};

#endif /* !MUSHROOM_HPP_ */
