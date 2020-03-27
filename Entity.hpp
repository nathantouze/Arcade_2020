/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by jfournier,
*/

#ifndef OOP_ARCADE_2019_ENTITY_HPP
#define OOP_ARCADE_2019_ENTITY_HPP

#include "IEntity.hpp"

class Entity : public IEntity {
    public:
    Entity(TypeEntity type, int x, int y);
    ~Entity() override;
    TypeEntity getType() const override;
    void setType(TypeEntity type) override;
    int getPosX() const override;
    void setPosX(int x) override;
    int getPosY() const override;
    void setPosY(int y) override;
    void updatePos(int x, int y) override;
    private:
    TypeEntity _type;
    int _x;
    int _y;
    protected:
};

#endif //OOP_ARCADE_2019_ENTITY_HPP