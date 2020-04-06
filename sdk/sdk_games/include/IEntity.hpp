/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by jfournier,
*/
#ifndef OOP_ARCADE_2019_IENTITY_HPP
#define OOP_ARCADE_2019_IENTITY_HPP

#include "TypeEntity.hpp"

class IEntity {
    public:
    virtual ~IEntity() = default;
    virtual TypeEntity getType() const = 0;
    virtual void setType(TypeEntity type) = 0;
    virtual int getPosX() const = 0;
    virtual void setPosX(int x) = 0;
    virtual int getPosY() const = 0;
    virtual void setPosY(int y) = 0;
    virtual void updatePos(int x, int y) = 0;
    private:
    protected:
};

#endif //OOP_ARCADE_2019_IENTITY_HPP
