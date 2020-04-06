/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by ntouze,
*/

#include "LibSfml.hpp"

/* Constructor */

LibSFML::LibSFML()
{
    sf::Font *font = new sf::Font();

    font->loadFromFile("assets/sfml/font/BarcadeFont.ttf");
    _fontResources[TITLEMENU] = font;
    _boxMap["GraphLib"] = new sf::RectangleShape({(sf::Vector2f(475, 725))});
    _boxMap["GamesLib"] = new sf::RectangleShape({(sf::Vector2f(475, 725))});
    _boxMap["Name"] = new sf::RectangleShape({(sf::Vector2f(500, 95))});
    _boxMap["Score"] = new sf::RectangleShape({(sf::Vector2f(600, 465))});
    _boxMap["Play"] = new sf::RectangleShape({(sf::Vector2f(300, 100))});
    _boxMap["ARCADE"] = new sf::RectangleShape({(sf::Vector2f(600, 125))});
    //_menuMusic.loadMusic("assets/sfml/music/menu-arcade.ogg");
}

/* Destructor */

LibSFML::~LibSFML()
{
}

/* Window management */

void LibSFML::initWindow()
{
    _window = new sf::RenderWindow(sf::VideoMode(SFML_WINDOW_WIDTH, SFML_WINDOW_HEIGHT), "My_Arcade");
    _isOpen = true;
}

void LibSFML::destroyWindow()
{
    _window->close();
    _isOpen = false;
}

void LibSFML::oneCycleDisplay()
{
    _window->display();
}

void LibSFML::oneCycleClear()
{
    sf::Texture *texture = nullptr;
    sf::Sprite sprite;

    if (_textureResources.find(BACKGROUND) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile("assets/sfml/sprite/menu-arcade.png");
        _textureResources[BACKGROUND] = texture;
    }
    sprite.setTexture(*_textureResources[BACKGROUND]);
    sprite.setPosition(0, 0);
    _window->clear(sf::Color::Black);
    _window->draw(sprite);
}

bool LibSFML::isOpen() const
{
    return (_isOpen);
}

/* Set and display Menu Arcade */

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

void LibSFML::setMenuBoxInfo(const std::vector<std::string> &list, const int &idx, std::string boxName, std::string errorText)
{
    size_t alpha = 255;
    std::string text = "";

    if (list.empty())
        text = errorText;
    setAttributes({(_boxMap[boxName]->getPosition().x + 25), (_boxMap[boxName]->getPosition().y + 100)}, sf::Color(0, 0, 0), text,\
    new sf::RectangleShape({(sf::Vector2f((_boxMap[boxName]->getSize().x - 50), (_boxMap[boxName]->getSize().y - 125)))}), 25);
    if (list.size() > 0) {
        for (size_t index = 0; index < list.size(); index++) {
            alpha = (idx == (int)index) ? 255 : 200;
            setAttributes({(_boxMap[boxName]->getPosition().x + 25), ((_boxMap[boxName]->getPosition().y + 100) + index * ((_boxMap[boxName]->getSize().y - 125)/list.size()))},\
            sf::Color(0, 0, 200, alpha), list[index],\
            new sf::RectangleShape({(sf::Vector2f((_boxMap[boxName]->getSize().x - 50), ((_boxMap[boxName]->getSize().y - 125)/list.size())))}), 15);
        }
    }
}

void LibSFML::displayMenu(const MenuInfo &menu)
{
    std::string text;

    setBox(menu);
    setMenuBoxInfo(menu.getGraphList(), menu.getGraphIdx(), "GraphLib", "No graphLib\n\nin directory\n\n/lib");
    setMenuBoxInfo(menu.getGameList(), menu.getGameIdx(), "GamesLib", "No game\n\nin directory\n\n/games");
    if (menu.getGameScores().empty())
        text = "No score available";
    setAttributes({(_boxMap["Score"]->getPosition().x + 25), (_boxMap["Score"]->getPosition().y + 100)}, sf::Color(0, 0, 0), text,\
    new sf::RectangleShape({(sf::Vector2f((_boxMap["Score"]->getSize().x - 50), (_boxMap["Score"]->getSize().y - 125)))}), 25);
    if (menu.getGameScores().size() > 0) {
        for (size_t index = 0; index < 5; index++) {
            setAttributes({(_boxMap["Score"]->getPosition().x + 25), ((_boxMap["Score"]->getPosition().y + 100) + index * ((_boxMap["Score"]->getSize().y - 125)/5/*More generic : menu.getGameScores().size()*/))},\
            sf::Color(0, 0, 200), menu.getGameScores()[index].first + " : " + menu.getGameScores()[index].second,\
            new sf::RectangleShape({(sf::Vector2f((_boxMap["Score"]->getSize().x - 50), ((_boxMap["Score"]->getSize().y - 125)/5/*More generic : menu.getGameScores().size()*/)))}), 15);
        }
    }
}

/* Search and set function */

sf::Text LibSFML::searchFontAndSetText(const IEntity &entity, std::pair<std::string, std::string> info, size_t size, sf::Color color, TypeEntity type)
{
    sf::Font *font = NULL;
    sf::Text text;

    if (_fontResources.find(type) == _fontResources.end()) {
        font = new sf::Font();
        font->loadFromFile(info.first);
        _fontResources[entity.getType()] = font;
    }
    text.setFont(*_fontResources[entity.getType()]);
    text.setString(info.second);
    text.setFillColor(color);
    text.setCharacterSize(size);
    text.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    return (text);
}

sf::Sprite LibSFML::searchTextureAndSetSprite(const IEntity &entity, std::string path, sf::IntRect *rect)
{
    sf::Texture *texture = NULL;
    sf::Sprite sprite;
    float scale = 1;

    if (_textureResources.find(entity.getType()) == _textureResources.end()) {
        texture = new sf::Texture();
        texture->loadFromFile(path);
        _textureResources[entity.getType()] = texture;
    }
    sprite.setTexture(*_textureResources[entity.getType()]);
    if (rect)
        sprite.setTextureRect(*rect);
    if (sprite.getLocalBounds().width > _mapSize.second.x)
        scale = _mapSize.second.x / sprite.getLocalBounds().width;
    else if (sprite.getLocalBounds().height > _mapSize.second.y)
        scale = _mapSize.second.y / sprite.getLocalBounds().height;
    sprite.scale(sf::Vector2f(scale, scale));
    sprite.setPosition(setEntityPos(entity.getPosX(), entity.getPosY()));
    return (sprite);
}

/* Map management */

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

/* Draw Function */

void LibSFML::drawError(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/error.png", nullptr);

    _window->draw(sprite);
}

void LibSFML::drawTitleMenu(const IEntity &entity)
{
    sf::Text text = searchFontAndSetText(entity, std::pair<std::string, std::string>("assets/sfml/font/BarcadeFont.ttf", "ARCADE"), 24, sf::Color::White, entity.getType());

    _window->draw(text);
}

void LibSFML::drawBonus1(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/player3andbonus1.png", new sf::IntRect(3, 195, 56, 60));

    _window->draw(sprite);
}

void LibSFML::drawPlayer2(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/player2.png", nullptr);

    _window->draw(sprite);
}

void LibSFML::drawPlayer3(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/player3andbonus1.png", new sf::IntRect(64, 5, 52, 52));

    _window->draw(sprite);
}

void LibSFML::drawPlayer4(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/player4.png", nullptr);

    _window->draw(sprite);
}

void LibSFML::drawVictory(const IEntity &entity)
{
    sf::Text text = searchFontAndSetText(entity, std::pair<std::string, std::string>("assets/sfml/font/BarcadeFont.ttf", "GAME WON"), 60, sf::Color::Yellow, entity.getType());

    _window->draw(text);
}

void LibSFML::drawDefeat(const IEntity &entity)
{
    sf::Text text = searchFontAndSetText(entity, std::pair<std::string, std::string>("assets/sfml/font/BarcadeFont.ttf", "GAME LOST"), 60, sf::Color::Red, entity.getType());

    _window->draw(text);
}

void LibSFML::drawPlayer1(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/player1.png", nullptr);

    _window->draw(sprite);
}

void LibSFML::drawProjectile(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/projectile.png", nullptr);

    _window->draw(sprite);
}

void LibSFML::drawWall(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/wall.png", nullptr);

    _window->draw(sprite);
}

void LibSFML::drawWall1(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/mushrooms.png", new sf::IntRect(0, 0, 31, 34));

    _window->draw(sprite);
}

void LibSFML::drawWall2(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/mushrooms.png", new sf::IntRect(31, 0, 31, 34));

    _window->draw(sprite);
}

void LibSFML::drawWall3(const IEntity &entity)
{
    sf::Sprite sprite = searchTextureAndSetSprite(entity, "assets/sfml/sprite/mushrooms.png", new sf::IntRect(62, 0, 31, 34));

    _window->draw(sprite);
}

void LibSFML::drawEntity(const IEntity &entity)
{
    switch (entity.getType()) {
    case TITLEMENU:
        drawTitleMenu(entity);
        break;
    case MAP:
        setMap({entity.getPosX(), entity.getPosY()});
        break;
    case BONUS_1:
        drawBonus1(entity);
        break;
    case PLAYER_1:
        drawPlayer1(entity);
        break;
    case PLAYER_2:
        drawPlayer2(entity);
        break;
    case PLAYER_3:
        drawPlayer3(entity);
        break;
    case PLAYER_4:
        drawPlayer4(entity);
        break;
    case GAME_WON:
        drawVictory(entity);
        break;
    case GAME_LOST:
        drawDefeat(entity);
        break;
    case PROJECTILE:
        drawProjectile(entity);
        break;
    case WALL_1:
        drawWall(entity);
        break;
    case WALL_2:
        drawWall1(entity);
        break;
    case WALL_3:
        drawWall2(entity);
        break;
    case WALL_4:
        drawWall3(entity);
        break;
    default:
        drawError(entity);
        break;
    }
}

/* Event Listener */

KeyBind LibSFML::eventListener()
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
                return(A);
            case sf::Keyboard::B:
                return(B);
            case sf::Keyboard::C:
                return(C);
            case sf::Keyboard::D:
                return(D);
            case sf::Keyboard::E:
                return(E);
            case sf::Keyboard::F:
                return(F);
            case sf::Keyboard::G:
                return(G);
            case sf::Keyboard::H:
                return(H);
            case sf::Keyboard::I:
                return(I);
            case sf::Keyboard::J:
                return(J);
            case sf::Keyboard::K:
                return(K);
            case sf::Keyboard::L:
                return(L);
            case sf::Keyboard::M:
                return(M);
            case sf::Keyboard::N:
                return(N);
            case sf::Keyboard::O:
                return(O);
            case sf::Keyboard::P:
                return(P);
            case sf::Keyboard::Q:
                return(Q);
            case sf::Keyboard::R:
                return(R);
            case sf::Keyboard::S:
                return(S);
            case sf::Keyboard::T:
                return(T);
            case sf::Keyboard::U:
                return(U);
            case sf::Keyboard::V:
                return(V);
            case sf::Keyboard::W:
                return(W);
            case sf::Keyboard::X:
                return(X);
            case sf::Keyboard::Y:
                return(Y);
            case sf::Keyboard::Z:
                return(Z);
            case sf::Keyboard::BackSpace:
                return (RETURN);
            default:
                return (NO_EVENT);
            }
        }
    }
    return (NO_EVENT);
}

/* END_OF_FILE */