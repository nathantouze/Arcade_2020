/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NCURSESclass
*/

#include "AllegroLib.hpp"

int AllegroLib::getPosOnWindow(int windowSize, int mapSize, int posOnMap)
{
    int posRef = windowSize / 2;

    if (posOnMap > mapSize / 2) {
        posRef += (posOnMap - (mapSize / 2)) * 20;
    } else {
        posRef -= ((mapSize / 2) - posOnMap) * 20;
    }
    return (posRef);
}

void AllegroLib::displayEntityWithAllegro(TypeEntity type, int posX, int posY)
{
    switch (type) {
        case PLAYER_1:
            _allegroPicture.displayPicture("./assets/allegro/player_1.png", posX, posY);
            break;
        case PLAYER_2:
            _allegroPicture.displayPicture("./assets/allegro/player_2.png", posX, posY);
            break;
        case PLAYER_3:
            _allegroPicture.displayPicture("./assets/allegro/player_3.png", posX, posY);
            break;
        case PLAYER_4:
            _allegroPicture.displayPicture("./assets/allegro/player_4.png", posX, posY);
            break;
        case ENEMY_1:
            _allegroPicture.displayPicture("./assets/allegro/enemy_1.png", posX, posY);
            break;
        case ENEMY_2:
            _allegroPicture.displayPicture("./assets/allegro/enemy_2.png", posX, posY);
            break;
        case ENEMY_3:
            _allegroPicture.displayPicture("./assets/allegro/enemy_3.png", posX, posY);
            break;
        case WALL_1:
            _allegroPicture.displayPicture("./assets/allegro/wall_1.png", posX, posY);
            break;
        case WALL_2:
            _allegroPicture.displayPicture("./assets/allegro/wall_2.png", posX, posY);
            break;
        case WALL_3:
            _allegroPicture.displayPicture("./assets/allegro/wall_3.png", posX, posY);
            break;
        case WALL_4:
            _allegroPicture.displayPicture("./assets/allegro/wall_4.png", posX, posY);
            break;
        case BONUS_1:
            _allegroPicture.displayPicture("./assets/allegro/bonus_1.png", posX, posY);
            break;
        case BONUS_2:
            _allegroPicture.displayPicture("./assets/allegro/bonus_2.png", posX, posY);
            break;
        case BONUS_3:
            _allegroPicture.displayPicture("./assets/allegro/bonus_3.png", posX, posY);
            break;
        case PROJECTILE:
            _allegroPicture.displayPicture("./assets/allegro/projectile.png", posX, posY);
            break;
        case GAME_WON:
            _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "You WIN", al_map_rgb(255, 255, 255), posX, posY);
            break;
        case GAME_LOST:
            _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "You LOSE", al_map_rgb(255, 255, 255), posX, posY);
            break;
        case ERROR:
            _allegroPicture.displayPicture("./assets/allegro/error.png", posX, posY);
            break;
        /*case FLOOR:
            _allegroPicture.displayPicture("./assets/batman.png", posX, posY);
            break;
        case BACKGROUND:
            _allegroPicture.displayPicture("./assets/batman.png", posX, posY);
            break;
        case TITLEMENU:
            _allegroPicture.displayPicture("./assets/batman.png", posX, posY);
            break;
        case TITLEGAME:
            _allegroPicture.displayPicture("./assets/batman.png", posX, posY);
            break;
        */
        default:
            break;
    }
}

void AllegroLib::drawEntity(const IEntity &entity)
{
    TypeEntity type = entity.getType();
    int posXOnWindow;
    int posYOnWindow;

    if (type == MAP) {
        _maxXMap = entity.getPosX();
        _maxYMap = entity.getPosY();
    } else {
        posXOnWindow = getPosOnWindow(1920, _maxXMap, entity.getPosX());
        posYOnWindow = getPosOnWindow(1080, _maxYMap, entity.getPosY());
    }
    displayEntityWithAllegro(type, posXOnWindow, posYOnWindow);
}

void AllegroLib::oneCycleDisplay()
{
    _allegroManager.display();
}

void AllegroLib::displayMenu(const MenuInfo &menu)
{
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);
    al_draw_rectangle(1, 25, 1920, 125, white, 1);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 48, "Arcade", white, 770, 50);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Scores", white, 900, 500);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 18, "Credits :", white, 150, 700);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 12, "Darius", white, 150, 750);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 12, "Rezz", white, 150, 800);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 12, "et Dark Vador", white, 150, 850);
    _allegroText.drawText("./assets/BarcadeFont.ttf", 12, "Les heros de Arcadia", white, 150, 900);
    _graphFolder.setFolderSelected(false);
    _gamesFolder.setFolderSelected(false);
    _graphFolder.setAllegroText(&_allegroText);
    _gamesFolder.setAllegroText(&_allegroText);
    _scoresFolder.setAllegroText(&_allegroText);

    switch (menu.getActiveBoxIdx()) {
    case 0:
        _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Pick Your Lib", yellow, 120, 195);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Pick Your Game", white, 860, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Player", white, 1560, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, menu.getPlayerName(), white, 1560, 270);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Start", white, 1560, 500);
        _graphFolder.setFolderSelected(true);
        break;

    case 1:
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Pick Your Lib", white, 160, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Pick Your Game", yellow, 820, 195);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Player", white, 1560, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, menu.getPlayerName(), white, 1560, 270);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Start", white, 1560, 500);
        _gamesFolder.setFolderSelected(true);
        break;

    case 2:
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Pick Your Lib", white, 160, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Pick Your Game", white, 860, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Player", yellow, 1500, 195);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, menu.getPlayerName(), yellow, 1560, 270);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 36, "Start", white, 1560, 500);
        break;

    case 3:
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Pick Your Lib", white, 160, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Pick Your Game", white, 860, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, "Player", white, 1560, 200);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 24, menu.getPlayerName(), white, 1560, 270);
        _allegroText.drawText("./assets/BarcadeFont.ttf", 48, "Start", yellow, 1500, 500);
    default:
        break;
    }
    _graphFolder.setFiles(menu.getGraphList());
    _graphFolder.setPosCursor(menu.getGraphIdx());
    _gamesFolder.setFiles(menu.getGameList());
    _gamesFolder.setPosCursor(menu.getGameIdx());
    _scoresFolder.setScores(menu.getGameScores());
    _graphFolder.drawFolder();
    _gamesFolder.drawFolder();
    _scoresFolder.drawScores();
    (void) menu;
}

void AllegroLib::oneCycleClear()
{
    _allegroManager.clearWindow(0, 0, 0);
}

KeyBind AllegroLib::eventListener()
{
    ALLEGRO_EVENT eventCatch = {0};
    
    if (_allegroEvent.getNextEvent(&eventCatch) == false)
        return (NO_EVENT);
    switch (eventCatch.type) {
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
        return EXIT;
        break;
    case ALLEGRO_EVENT_KEY_DOWN:
        return (analyseKeyboardEvent(&eventCatch));
        break;
    
    default:
        return (NO_EVENT);
        break;
    }
    return (NO_EVENT);
}

bool AllegroLib::isOpen() const
{
    return _isOpen;
}

void AllegroLib::destroyWindow() 
{
    _isOpen = false;
    _allegroManager.destroyWindow();
    _allegroEvent.destroyEvents();
}

void AllegroLib::initWindow()
{
    _isOpen = true;
    _maxXMap = 0;
    _maxYMap = 0;
    _graphFolder.setPosOnScreen(90, 270);
    _gamesFolder.setPosOnScreen(790, 270);
    _scoresFolder.setPosOnScreen(800, 600);
    _allegroManager.createWindow(1920, 1080);
    _allegroEvent.initEvents();
    _allegroEvent.addScreenEvents(_allegroManager.getWindow());
    _allegroEvent.addKeyboardEvents();
    _allegroText.loadFont("./assets/BarcadeFont.ttf", 48);
    _allegroText.loadFont("./assets/BarcadeFont.ttf", 36);
    _allegroText.loadFont("./assets/BarcadeFont.ttf", 24);
    _allegroText.loadFont("./assets/BarcadeFont.ttf", 12);
    _allegroText.loadFont("./assets/BarcadeFont.ttf", 18);
    _allegroPicture.loadPicture("./assets/allegro/player_1.png");
    _allegroPicture.loadPicture("./assets/allegro/player_2.png");
    _allegroPicture.loadPicture("./assets/allegro/player_3.png");
    _allegroPicture.loadPicture("./assets/allegro/player_4.png");
    _allegroPicture.loadPicture("./assets/allegro/enemy_1.png");
    _allegroPicture.loadPicture("./assets/allegro/enemy_2.png");
    _allegroPicture.loadPicture("./assets/allegro/enemy_3.png");
    _allegroPicture.loadPicture("./assets/allegro/wall_1.png");
    _allegroPicture.loadPicture("./assets/allegro/wall_2.png");
    _allegroPicture.loadPicture("./assets/allegro/wall_3.png");
    _allegroPicture.loadPicture("./assets/allegro/wall_4.png");
    _allegroPicture.loadPicture("./assets/allegro/bonus_1.png");
    _allegroPicture.loadPicture("./assets/allegro/bonus_2.png");
    _allegroPicture.loadPicture("./assets/allegro/bonus_3.png");
    _allegroPicture.loadPicture("./assets/allegro/projectile.png");
    _allegroPicture.loadPicture("./assets/allegro/error.png");
}

AllegroLib::AllegroLib() : _isOpen(false)
{
    _allegroManager.initAllegro();
    _allegroText.initText();
}

KeyBind AllegroLib::analyseKeyboardEvent(ALLEGRO_EVENT *event) const
{
    switch (event->keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            return UP_KEY;
            break;
        case ALLEGRO_KEY_DOWN:
            return DOWN_KEY;
            break;
        case ALLEGRO_KEY_RIGHT:
            return RIGHT_KEY;
            break;
        case ALLEGRO_KEY_LEFT:
            return LEFT_KEY;
            break;
        case ALLEGRO_KEY_A:
            return A;
            break;
        case ALLEGRO_KEY_B:
            return B;
            break;
        case ALLEGRO_KEY_C:
            return C;
            break;
        case ALLEGRO_KEY_D:
            return D;
            break;
        case ALLEGRO_KEY_E:
            return E;
            break;
        case ALLEGRO_KEY_F:
            return F;
            break;
        case ALLEGRO_KEY_G:
            return G;
            break;
        case ALLEGRO_KEY_H:
            return H;
            break;
        case ALLEGRO_KEY_I:
            return I;
            break;
        case ALLEGRO_KEY_J:
            return J;
            break;
        case ALLEGRO_KEY_K:
            return K;
            break;
        case ALLEGRO_KEY_L:
            return L;
            break;
        case ALLEGRO_KEY_M:
            return M;
            break;
        case ALLEGRO_KEY_N:
            return N;
            break;
        case ALLEGRO_KEY_O:
            return O;
            break;
        case ALLEGRO_KEY_P:
            return P;
            break;
        case ALLEGRO_KEY_Q:
            return Q;
            break;
        case ALLEGRO_KEY_R:
            return R;
            break;
        case ALLEGRO_KEY_S:
            return S;
            break;
        case ALLEGRO_KEY_T:
            return T;
            break;
        case ALLEGRO_KEY_U:
            return U;
            break;
        case ALLEGRO_KEY_V:
            return V;
            break;
        case ALLEGRO_KEY_W:
            return W;
            break;
        case ALLEGRO_KEY_X:
            return X;
            break;
        case ALLEGRO_KEY_Y:
            return Y;
            break;
        case ALLEGRO_KEY_Z:
            return Z;
            break;
        case ALLEGRO_KEY_BACKSPACE:
            return RETURN;
            break;
        case ALLEGRO_KEY_ESCAPE:
            return EXIT;
            break;
        case ALLEGRO_KEY_F1:
            return PREV_GAME;
            break;
        case ALLEGRO_KEY_F2:
            return NEXT_GAME;
            break;
        case ALLEGRO_KEY_F3:
            return PREV_LIB;
            break;
        case ALLEGRO_KEY_F4:
            return NEXT_LIB;
            break;
        case ALLEGRO_KEY_F5:
            return MENU;
            break;
        case ALLEGRO_KEY_F6:
            return RESTART;
            break;
        case ALLEGRO_KEY_ENTER:
            return VALID;
            break;
        case ALLEGRO_KEY_SPACE:
            return SPACE;
            break;
    }
    return (NO_EVENT);
}

AllegroLib::~AllegroLib()
{
}