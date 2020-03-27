/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by ntouze,
*/
#ifndef OOP_ARCADE_2019_LIBSFML_HPP
#define OOP_ARCADE_2019_LIBSFML_HPP

#define SFML_WINDOW_WIDTH 1920
#define SFML_WINDOW_HEIGHT 1080

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ILibIO.hpp"
#include "TypeEntity.hpp"
#include "Event.hpp"
#include "Entity.hpp"
#include <iostream>

class LibSFML : public ILibIO {
    public:
        void initWindow();
        void display() const;
        void drawEntity(const IEntity &entity);
        void displayMenu(const MenuInfo &menu);
        bool isOpen() const;
        Event eventListener() const;
        void clearWindow();
        void destroyWindow();
        LibSFML();
        ~LibSFML();
    private:
        sf::RenderWindow *_window;
        std::map<TypeEntity, sf::Font*> _fontResources;
        std::map<TypeEntity, sf::Texture*> _textureResources;
        std::map<std::string, sf::RectangleShape*> _boxMap;
        std::pair<sf::Vector2i, sf::Vector2i> _mapSize;
        bool _isOpen;
        sf::Vector2f setEntityPos(int posX, int posY);
        void setMap(sf::Vector2i mapPos);
        void setBox(const MenuInfo &menu);
        void setAttributes(sf::Vector2f pos, sf::Color color, const std::string &boxName, const MenuInfo &menu);
        void setAttributes(sf::Vector2f pos, sf::Color color, const std::string &boxName, sf::RectangleShape *rect,  size_t charSize);
        /* Draw */
        void drawWall(const IEntity &entity);
        void drawBonus(const IEntity &entity);
        void drawSnakeHead(const IEntity &entity);
        void drawSnakeBody(const IEntity &entity);
        void drawSnakeTail(const IEntity &entity);
        void drawPlayer(const IEntity &entity);
        void drawTitleMenu(const IEntity &entity);
        void drawError(const IEntity &entity);
        void drawVictory(const IEntity &entity);
        void drawDefeat(const IEntity &entity);
        void drawGnome(const IEntity &entity);
        void drawProjectile(const IEntity &entity);
        void drawMushroom1(const IEntity &entity);
        void drawMushroom2(const IEntity &entity);
        void drawMushroom3(const IEntity &entity);
};

extern "C" {
    ILibIO *entryPoint() {
        return (new LibSFML());
    }
}

#endif //OOP_ARCADE_2019_LIBSFML_HPP
