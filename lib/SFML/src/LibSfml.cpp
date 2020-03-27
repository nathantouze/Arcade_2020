/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by ntouze,
*/

#include "LibSfml.hpp"

void LibSFML::initWindow()
{
    _window = new sf::RenderWindow(sf::VideoMode(SFML_WINDOW_WIDTH, SFML_WINDOW_HEIGHT), "My_Arcade");
    _isOpen = true;
}

void LibSFML::display() const
{
    _window->display();
}

void LibSFML::setAttributes(sf::Vector2f pos, sf::Color color, const std::string &boxName, const MenuInfo &menu)
{
    sf::Text text;

    _boxMap[boxName]->setPosition(pos);
    _boxMap[boxName]->setFillColor(color);
    _window->draw(*_boxMap[boxName]);
    text.setFont(*_fontResources[TITLEMENU]);
    if (boxName == "Name") {
        text.setString(menu.getPlayerName());
        text.setFillColor(sf::Color(0, 0, 0));
        text.setCharacterSize(20);
    } else {
        if (boxName == "ARCADE")
            text.setCharacterSize(60);
        else
            text.setCharacterSize(40);
        text.setString(boxName);
        text.setFillColor(sf::Color(255,215,0));
    }
    text.setPosition(pos.x + _boxMap[boxName]->getSize().x / 2 - text.getLocalBounds().width / 2, pos.y + 25);
    _window->draw(text);
}

void LibSFML::setAttributes(sf::Vector2f pos, sf::Color rectColor, const std::string &boxName, sf::RectangleShape *rect, size_t charSize)
{
    sf::Text text;

    rect->setPosition(pos);
    rect->setFillColor(rectColor);
    rect->setOutlineThickness(5);
    rect->setOutlineColor(sf::Color(255, 215, 0));
    if (boxName.find(".so") != std::string::npos) {
        rect->setOutlineThickness(-10);
        rect->setOutlineColor(sf::Color(0, 200, 200));
    }
    _window->draw(*rect);
    text.setFont(*_fontResources[TITLEMENU]);
    text.setCharacterSize(charSize);
    text.setString(boxName);
    text.setFillColor(sf::Color(255, 255, 255));
    text.setPosition(pos.x + rect->getSize().x / 2 - text.getLocalBounds().width / 2, (boxName.find(".so") != std::string::npos)?pos.y + rect->getSize().y / 2 - text.getLocalBounds().height / 2:pos.y + 25);
    _window->draw(text);
}

void LibSFML::setBox(const MenuInfo &menu)
{
    size_t alpha = 255;

    alpha = (menu.getActiveBoxIdx() == 0)?255:200;
    setAttributes({25, 25}, sf::Color(250, 50, 50, alpha), "GraphLib", menu);
    alpha = (menu.getActiveBoxIdx() == 1)?255:200;
    setAttributes({1420, 25}, sf::Color(250, 50, 50, alpha), "GamesLib", menu);
    alpha = (menu.getActiveBoxIdx() == 2)?255:200;
    setAttributes({710, 175}, sf::Color(255, 127, 0, alpha), "Name", menu);
    setAttributes({660, 295}, sf::Color(255, 0, 255), "Score", menu);
    alpha = (menu.getActiveBoxIdx() == 3)?255:200;
    setAttributes({810, 800}, sf::Color(50, 50, 250, alpha), "Play", menu);
    setAttributes({660, 25}, sf::Color(0, 0, 0), "ARCADE", menu);
}

void LibSFML::displayMenu(const MenuInfo &menu)
{
    size_t alpha = 255;
    std::string text;

    setBox(menu);
    if (menu.getGraphList().empty())
        text = "No graphLib\n\nin directory\n\n/lib";
    setAttributes({(_boxMap["GraphLib"]->getPosition().x + 25), (_boxMap["GraphLib"]->getPosition().y + 100)}, sf::Color(0, 0, 0), text,\
    new sf::RectangleShape({(sf::Vector2f((_boxMap["GraphLib"]->getSize().x - 50), (_boxMap["GraphLib"]->getSize().y - 125)))}), 25);
    if (menu.getGraphList().size() > 0) {
        for (size_t index = 0; index < menu.getGraphList().size(); index++) {
            alpha = (menu.getGraphIdx() == (int)index)?255:200;
            setAttributes({(_boxMap["GraphLib"]->getPosition().x + 25), ((_boxMap["GraphLib"]->getPosition().y + 100) + index * ((_boxMap["GraphLib"]->getSize().y - 125)/menu.getGraphList().size()))},\
            sf::Color(0, 0, 200, alpha), menu.getGraphList()[index],\
            new sf::RectangleShape({(sf::Vector2f((_boxMap["GraphLib"]->getSize().x - 50), ((_boxMap["GraphLib"]->getSize().y - 125)/menu.getGraphList().size())))}), 15);
        }
    }
    if (menu.getGameList().empty())
        text = "No game\n\nin directory\n\n/games";
    setAttributes({(_boxMap["GamesLib"]->getPosition().x + 25), (_boxMap["GamesLib"]->getPosition().y + 100)}, sf::Color(0, 0, 0), text,\
    new sf::RectangleShape({(sf::Vector2f((_boxMap["GamesLib"]->getSize().x - 50), (_boxMap["GamesLib"]->getSize().y - 125)))}), 25);
    if (menu.getGameList().size() > 0) {
        for (size_t index = 0; index < menu.getGameList().size(); index++) {
            alpha = (menu.getGameIdx() == (int)index)?255:200;
            setAttributes({(_boxMap["GamesLib"]->getPosition().x + 25), ((_boxMap["GamesLib"]->getPosition().y + 100) + index * ((_boxMap["GamesLib"]->getSize().y - 125)/menu.getGameList().size()))},\
            sf::Color(0, 0, 200, alpha), menu.getGameList()[index],\
            new sf::RectangleShape({(sf::Vector2f((_boxMap["GamesLib"]->getSize().x - 50), ((_boxMap["GamesLib"]->getSize().y - 125)/menu.getGameList().size())))}), 15);
        }
    }
    if (menu.getGameScores().empty())
        text = "No score available";
    setAttributes({(_boxMap["Score"]->getPosition().x + 25), (_boxMap["Score"]->getPosition().y + 100)}, sf::Color(0, 0, 0), text,\
    new sf::RectangleShape({(sf::Vector2f((_boxMap["Score"]->getSize().x - 50), (_boxMap["Score"]->getSize().y - 125)))}), 25);
    if (menu.getGameScores().size() > 0) {
        size_t index = 0;
        for (std::pair<std::string, int> element : menu.getGameScores()) {
            setAttributes({(_boxMap["Score"]->getPosition().x + 25), ((_boxMap["Score"]->getPosition().y + 100) + index * ((_boxMap["Score"]->getSize().y - 125)/menu.getGameScores().size()))},\
            sf::Color(0, 0, 200), element.first + " : " + std::to_string(element.second),\
            new sf::RectangleShape({(sf::Vector2f((_boxMap["Score"]->getSize().x - 50), ((_boxMap["Score"]->getSize().y - 125)/menu.getGameScores().size())))}), 15);
            index++;
        }
    }
    drawEntity(Entity(MAP, 20, 20));
}

void LibSFML::drawPlayer(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/batman.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    sprite.scale(sf::Vector2f(0.35, 0.35));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawTitleMenu(const IEntity &entity)
{
    sf::Font *font = NULL;
    sf::Text text;

    if (_fontResources.find(entity.getType()) == _fontResources.end()) {
        font = new sf::Font();
        font->loadFromFile("assets/BarcadeFont.ttf");
        _fontResources[entity.getType()] = font;
    }
    text.setFont(*_fontResources[entity.getType()]);
    text.setString("ARCADE");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    text.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(text);
}

void LibSFML::drawError(const IEntity &entity)
{
    sf::Font *font = NULL;
    sf::Text text;

    if (_fontResources.find(ERROR) == _fontResources.end()) {
        font = new sf::Font();
        font->loadFromFile("assets/BarcadeFont.ttf");
        _fontResources[ERROR] = font;
    }
    text.setFont(*_fontResources[entity.getType()]);
    text.setString("Error");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    text.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(text);
}

void LibSFML::drawWall(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/wall.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawBonus(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/snake-graphics.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    sprite.setTextureRect(sf::IntRect(3, 195, 56, 60));
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawSnakeHead(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/snake-head.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawSnakeBody(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/snake-graphics.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    sprite.setTextureRect(sf::IntRect(64, 5, 52, 52));
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawSnakeTail(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/snake-tail.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawVictory(const IEntity &entity)
{
    sf::Font *font = NULL;
    sf::Text text;

    if (_fontResources.find(entity.getType()) == _fontResources.end()) {
        font = new sf::Font();
        font->loadFromFile("assets/BarcadeFont.ttf");
        _fontResources[entity.getType()] = font;
    }
    text.setFont(*_fontResources[entity.getType()]);
    text.setString("GAME WON");
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(60);
    text.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(text);
}

void LibSFML::drawDefeat(const IEntity &entity)
{
    sf::Font *font = NULL;
    sf::Text text;

    if (_fontResources.find(entity.getType()) == _fontResources.end()) {
        font = new sf::Font();
        font->loadFromFile("assets/BarcadeFont.ttf");
        _fontResources[entity.getType()] = font;
    }
    text.setFont(*_fontResources[entity.getType()]);
    text.setString("GAME LOST");
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(60);
    text.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(text);
}

void LibSFML::drawGnome(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/gnome.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawProjectile(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/projectile.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawMushroom1(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/mushrooms.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    sprite.setTextureRect(sf::IntRect(0, 0, 31, 34));
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawMushroom2(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/mushrooms.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    sprite.setTextureRect(sf::IntRect(31, 0, 31, 34));
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}

void LibSFML::drawMushroom3(const IEntity &entity)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/mushrooms.png");
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    sprite.setTextureRect(sf::IntRect(62, 0, 31, 34));
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    _window->draw(sprite);
}


sf::Vector2f LibSFML::setEntityPos(int posX, int posY)
{
    return (sf::Vector2f(_mapSize.first.x + _mapSize.second.x * posX, _mapSize.first.y + _mapSize.second.y * posY));
}

void LibSFML::setMap(sf::Vector2i mapPos)
{
    std::pair<sf::Vector2i, sf::Vector2i> dataMap;

    dataMap.first = sf::Vector2i((SFML_WINDOW_WIDTH / 2) - (SFML_WINDOW_HEIGHT / 2 - 100), 100);
    dataMap.second = sf::Vector2i((SFML_WINDOW_WIDTH - dataMap.first.x * 2) / mapPos.x, (SFML_WINDOW_HEIGHT - dataMap.first.y * 2) / mapPos.y);
    _mapSize = dataMap;
}

void LibSFML::drawEntity(const IEntity &entity)
{
    switch (entity.getType()) {
    case PLAYER:
        drawPlayer(entity);
        break;
    case TITLEMENU:
        drawTitleMenu(entity);
        break;
    case MAP:
        setMap({entity.getPosX(), entity.getPosY()});
        break;
    case WALL:
        drawWall(entity);
        break;
    case BONUS:
        drawBonus(entity);
        break;
    case SNAKE_HEAD:
        drawSnakeHead(entity);
        break;
    case SNAKE_BODY:
        drawSnakeBody(entity);
        break;
    case SNAKE_TAIL:
        drawSnakeTail(entity);
        break;
    case GAME_WON:
        drawVictory(entity);
        break;
    case GAME_LOST:
        drawDefeat(entity);
        break;
    case GNOME:
        drawGnome(entity);
        break;
    case SHOOT:
        drawProjectile(entity);
        break;
    case MUSHROOM_1:
        drawMushroom1(entity);
        break;
    case MUSHROOM_2:
        drawMushroom2(entity);
        break;
    case MUSHROOM_3:
        drawMushroom3(entity);
        break;
    default:
        drawError(entity);
        break;
    }
}

bool LibSFML::isOpen() const
{
    return (_isOpen);
}

Event LibSFML::eventListener() const
{
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return (EXIT);
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Escape:
                return (EXIT);
            case sf::Keyboard::Space:
                return (SPACE);
            case sf::Keyboard::Left:
                return (LEFT_KEY);
            case sf::Keyboard::Right:
                return (RIGHT_KEY);
            case sf::Keyboard::Up:
                return (UP_KEY);
            case sf::Keyboard::Down:
                return (DOWN_KEY);
            case sf::Keyboard::Return:
                return (VALID);
            case sf::Keyboard::F1:
                return (PREV_GAME);
            case sf::Keyboard::F2:
                return (NEXT_GAME);
            case sf::Keyboard::F3:
                return (PREV_LIB);
            case sf::Keyboard::F4:
                return (NEXT_LIB);
            case sf::Keyboard::F5:
                return (MENU);
            case sf::Keyboard::F6:
                return (RESTART);
            case sf::Keyboard::A:
                return(A_KEY);
            case sf::Keyboard::B:
                return(B_KEY);
            case sf::Keyboard::C:
                return(C_KEY);
            case sf::Keyboard::D:
                return(D_KEY);
            case sf::Keyboard::E:
                return(E_KEY);
            case sf::Keyboard::F:
                return(F_KEY);
            case sf::Keyboard::G:
                return(G_KEY);
            case sf::Keyboard::H:
                return(H_KEY);
            case sf::Keyboard::I:
                return(I_KEY);
            case sf::Keyboard::J:
                return(J_KEY);
            case sf::Keyboard::K:
                return(K_KEY);
            case sf::Keyboard::L:
                return(L_KEY);
            case sf::Keyboard::M:
                return(M_KEY);
            case sf::Keyboard::N:
                return(N_KEY);
            case sf::Keyboard::O:
                return(O_KEY);
            case sf::Keyboard::P:
                return(P_KEY);
            case sf::Keyboard::Q:
                return(Q_KEY);
            case sf::Keyboard::R:
                return(R_KEY);
            case sf::Keyboard::S:
                return(S_KEY);
            case sf::Keyboard::T:
                return(T_KEY);
            case sf::Keyboard::U:
                return(U_KEY);
            case sf::Keyboard::V:
                return(V_KEY);
            case sf::Keyboard::W:
                return(W_KEY);
            case sf::Keyboard::X:
                return(X_KEY);
            case sf::Keyboard::Y:
                return(Y_KEY);
            case sf::Keyboard::Z:
                return(Z_KEY);
            case sf::Keyboard::BackSpace:
                return (RETURN);
            default:
                return (NO_EVENT);
            }
        }
    }
    return (NO_EVENT);
}

void LibSFML::clearWindow()
{
    sf::Texture *texture = nullptr;
    sf::Sprite sprite;

    if (_textureResources.find(BACKGROUND) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/menu-arcade.png");
        _textureResources[BACKGROUND] = texture;
    }
    sprite.setTexture(*_textureResources[BACKGROUND]);
    sprite.setPosition(0, 0);
    _window->clear(sf::Color::Black);
    _window->draw(sprite);
}

void LibSFML::destroyWindow()
{
    _window->close();
    _isOpen = false;
}

LibSFML::LibSFML()
{
    sf::Font *font = new sf::Font();

    font->loadFromFile("assets/BarcadeFont.ttf");
    _fontResources[TITLEMENU] = font;
    _boxMap["GraphLib"] = new sf::RectangleShape({(sf::Vector2f(475, 725))});
    _boxMap["GamesLib"] = new sf::RectangleShape({(sf::Vector2f(475, 725))});
    _boxMap["Name"] = new sf::RectangleShape({(sf::Vector2f(500, 95))});
    _boxMap["Score"] = new sf::RectangleShape({(sf::Vector2f(600, 465))});
    _boxMap["Play"] = new sf::RectangleShape({(sf::Vector2f(300, 100))});
    _boxMap["ARCADE"] = new sf::RectangleShape({(sf::Vector2f(600, 125))});
}

LibSFML::~LibSFML()
{
}