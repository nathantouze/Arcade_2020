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
#include "IDisplayModule.hpp"
#include "TypeEntity.hpp"
#include "KeyBind.hpp"
#include "Entity.hpp"
#include "Music.hpp"

class LibSFML : public IDisplayModule {
    public:
        /* Constructor */
        LibSFML();
        /* Destructor */
        ~LibSFML();
        /* Window management */
        void initWindow();
        void destroyWindow();
        bool isOpen() const;
        void oneCycleDisplay();
        void oneCycleClear();
        /* Draw Entity*/
        void drawEntity(const IEntity &entity);
        /* Event Listener */
        KeyBind eventListener();
        /* Display Menu Arcade */
        void displayMenu(const MenuInfo &menu);

    private:
        sf::RenderWindow *_window;
        std::map<TypeEntity, sf::Font*> _fontResources;
        std::map<TypeEntity, sf::Texture*> _textureResources;
        std::map<std::string, sf::RectangleShape*> _boxMap;
        std::pair<sf::Vector2i, sf::Vector2i> _mapSize;
        //Music _menuMusic;
        bool _isOpen;

        /* Search and set function */
        sf::Text searchFontAndSetText(const IEntity &entity, std::pair<std::string, std::string> info, size_t size, sf::Color color, TypeEntity type);
        sf::Sprite searchTextureAndSetSprite(const IEntity &entity, std::string path, sf::IntRect *rect);
        /* Map management */
        void setMap(sf::Vector2i mapPos);
        sf::Vector2f setEntityPos(int posX, int posY);
        /* Set Menu Arcade */
        void setAttributes(sf::Vector2f pos, sf::Color color, const std::string &boxName, const MenuInfo &menu);
        void setAttributes(sf::Vector2f pos, sf::Color color, const std::string &boxName, sf::RectangleShape *rect,  size_t charSize);
        void setBox(const MenuInfo &menu);
        void setMenuBoxInfo(const std::vector<std::string> &list, const int &idx, std::string boxName, std::string text);
        /* Draw Function*/
        void drawError(const IEntity &entity);
        void drawBonus1(const IEntity &entity);
        void drawPlayer1(const IEntity &entity);
        void drawPlayer2(const IEntity &entity);
        void drawPlayer3(const IEntity &entity);
        void drawPlayer4(const IEntity &entity);
        void drawTitleMenu(const IEntity &entity);
        void drawVictory(const IEntity &entity);
        void drawDefeat(const IEntity &entity);
        void drawProjectile(const IEntity &entity);
        void drawWall(const IEntity &entity);
        void drawWall1(const IEntity &entity);
        void drawWall2(const IEntity &entity);
        void drawWall3(const IEntity &entity);
        /* Music management */
        void loadMusic();
};

extern "C" {
    IDisplayModule *entryPoint() {
        return (new LibSFML());
    }
}

#endif //OOP_ARCADE_2019_LIBSFML_HPP
