/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Gnome
*/

#ifndef GNOME_HPP_
#define GNOME_HPP_

#include "Entity.hpp"
#include "MushroomManager.hpp"

class Gnome : public Entity {
    public:
        Gnome();
        ~Gnome();
        void moveUp(const MushroomManager &mushroomManager);
        void moveDown(const MushroomManager &mushroomManager);
        void moveLeft(const MushroomManager &mushroomManager);
        void moveRight(const MushroomManager &mushroomManager);
        void initGnome();
        bool isAlive() const;
        void setIsAlive(bool isAlive);
        Entity *getEntity();

    protected:
    private:
        bool _isAlive;
};

#endif /* !GNOME_HPP_ */
