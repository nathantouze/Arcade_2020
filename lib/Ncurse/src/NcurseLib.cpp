/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NCURSESclass
*/

#include "NcurseLib.hpp"
#include <string>
#include <cstring>

int NcurseLib::getmaxheight() const
{
    return _maxheight;
}

int NcurseLib::getmaxwidth() const
{
    return _maxwidth;
}

void NcurseLib::drawPlayer(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "P");
}

void NcurseLib::drawEnemy(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "E");
}

void NcurseLib::drawWall(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "W");
}

void NcurseLib::drawGnome(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "G");
}

void NcurseLib::drawShoot(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "|");
}

void NcurseLib::drawMushroom(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "M");
}

void NcurseLib::drawSnakeHead(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "H");
}

void NcurseLib::drawSnakeBody(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "B");
}

void NcurseLib::drawSnakeTail(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "T");
}

void NcurseLib::drawFloor(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "F");
}

void NcurseLib::drawBonus(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "O");
}

void NcurseLib::drawGameWon() const
{
    mvprintw(PADDING_HEIGHT - 2, PADDING_WIDTH, "GAME WON");
}

void NcurseLib::drawGameLost() const
{
    mvprintw(PADDING_HEIGHT - 2, PADDING_WIDTH, "GAME LOST");
}

void NcurseLib::drawError(const IEntity &_entity) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, "E");
}

void NcurseLib::drawScore(const IEntity &_entity) const
{
    std::string score = "SCORE: ";

    score.append(std::to_string(_entity.getPosX()));
    mvprintw(PADDING_HEIGHT - 2, PADDING_WIDTH * 2, score.c_str());
}

void NcurseLib::drawEntity(const IEntity &_entity)
{
    switch (_entity.getType()) {
        case PLAYER:
            drawPlayer(_entity);
            break;
        case ENEMY:
            drawEnemy(_entity);
            break;
        case WALL:
            drawWall(_entity);
            break;
        case MAP:
            break;
        case GNOME:
            drawGnome(_entity);
            break;
        case SHOOT:
            drawShoot(_entity);
            break;
        case MUSHROOM_1:
            drawMushroom(_entity);
            break;
        case MUSHROOM_2:
            drawMushroom(_entity);
            break;
        case MUSHROOM_3:
            drawMushroom(_entity);
            break;
        case SNAKE_HEAD:
            drawSnakeHead(_entity);
            break;
        case SNAKE_BODY:
            drawSnakeBody(_entity);
            break;
        case SNAKE_TAIL:
            drawSnakeTail(_entity);
            break;
        case FLOOR:
            drawFloor(_entity);
            break;
        case BONUS:
            drawBonus(_entity);
            break;
        case TITLEGAME:
            break;
        case TITLEMENU:
            break;
        case BACKGROUND:
            break;
        case GAME_WON:
            drawGameWon();
            break;
        case GAME_LOST:
            drawGameLost();
            break;
        case ERROR:
            drawError(_entity);
            break;
        case SCORE:
            drawScore(_entity);
            break;
        default:
            drawError(_entity);
            break;
    }
}

void NcurseLib::display() const
{

}

void NcurseLib::displayMenu(const MenuInfo &menu)
{
    std::vector<std::string> _libs = menu.getGraphList();
    std::vector<std::string> _games = menu.getGameList();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(2, _maxwidth / 2 - std::strlen("Arcade"), "ARCADE");
    attroff(COLOR_PAIR(1));

    // GRAPH LIB
    if (menu.getActiveBoxIdx() == 0) {
        attron(COLOR_PAIR(2));
        mvprintw(_maxheight / 4, _maxwidth / 6 - std::strlen("GRAPHLIB"), "GRAPHLIB");
        attroff(COLOR_PAIR(2));
    } else
        mvprintw(_maxheight / 4, _maxwidth / 6 - std::strlen("GRAPHLIB"), "GRAPHLIB");        
    if (menu.getGraphList().empty())
        mvprintw(_maxheight / 4 + 2, _maxwidth / 6 - std::strlen("GRAPHLIB"), "No graphlib.");
    else {
        for (int i = 0; static_cast<std::size_t>(i) < _libs.size(); i++) {
            if (menu.getGraphIdx() == i) {
                attron(COLOR_PAIR(2));
                mvprintw(_maxheight / 4 + 2 + (2 * i), _maxwidth / 6 - std::strlen("GRAPHLIB"), _libs.at(i).c_str());
                attroff(COLOR_PAIR(2));
            } else
                mvprintw(_maxheight / 4 + 2 + (2 * i), _maxwidth / 6 - std::strlen("GRAPHLIB"), _libs.at(i).c_str());
        }
    }
    // GAME LIB
    if (menu.getActiveBoxIdx() == 1) {
        attron(COLOR_PAIR(2));
        mvprintw(_maxheight / 4, _maxwidth / 2.5 - std::strlen("GAMESLIB"), "GAMESLIB");
        attroff(COLOR_PAIR(2));
    } else
        mvprintw(_maxheight / 4, _maxwidth / 2.5 - std::strlen("GAMESLIB"), "GAMESLIB");       
    if (menu.getGameList().empty())
        mvprintw(_maxheight / 4 + 2, _maxwidth / 2.5 - (std::strlen("GAMESLIB") * 2), "No gamelib.");
    else {
        for (int i = 0; static_cast<std::size_t>(i) < _games.size(); i++) {
            if (menu.getGameIdx() == i) {
                attron(COLOR_PAIR(2));
                mvprintw(_maxheight / 4 + 2 + (2 * i), _maxwidth / 2.5 - std::strlen("GAMESLIB"), _games.at(i).c_str());
                attroff(COLOR_PAIR(2));
            } else
                mvprintw(_maxheight / 4 + 2 + (2 * i), _maxwidth / 2.5 - std::strlen("GAMESLIB"), _games.at(i).c_str());
        }
    }

    // USERNAME
    if (menu.getActiveBoxIdx() == 2) {
        attron(COLOR_PAIR(2));
        mvprintw(_maxheight / 4, _maxwidth - _maxwidth / 2.5, "USERNAME");
        attroff(COLOR_PAIR(2));
    } else    
        mvprintw(_maxheight / 4, _maxwidth - _maxwidth / 2.5, "USERNAME");
    mvprintw(_maxheight / 4 + 2, _maxwidth - _maxwidth / 2.5, menu.getPlayerName().c_str());

    // PLAY
    if (menu.getActiveBoxIdx() == 3) {
        attron(COLOR_PAIR(2));
        mvprintw(_maxheight / 4, _maxwidth - _maxwidth / 6, "PLAY");
        attroff(COLOR_PAIR(2));
    } else
        mvprintw(_maxheight / 4, _maxwidth - _maxwidth / 6, "PLAY");
    attroff(A_BOLD);
}

void NcurseLib::clearWindow()
{
    clear();
}

Event NcurseLib::eventListener() const
{
    int ch = getch();

    switch (ch) {
        case KEY_EXIT:
            return (EXIT);
        case KEY_LEFT:
            return (LEFT_KEY);
        case KEY_RIGHT:
            return (RIGHT_KEY);
        case KEY_UP:
            return (UP_KEY);
        case KEY_DOWN:
            return (DOWN_KEY);
        case '\n':
            return (VALID);
        case KEY_F(1):
            return (PREV_GAME);
        case KEY_F(2):
            return (NEXT_GAME);
        case KEY_F(3):
            return (PREV_LIB);
        case KEY_F(4):
            return (NEXT_LIB);
        case KEY_F(5):
            return (MENU);
        case KEY_F(6):
            return (RESTART);
        case 'a':
            return(A_KEY);
        case 'b':
            return(B_KEY);
        case 'c':
            return(C_KEY);
        case 'd':
            return(D_KEY);
        case 'e':
            return(E_KEY);
        case 'f':
            return(F_KEY);
        case 'g':
            return(G_KEY);
        case 'h':
            return(H_KEY);
        case 'i':
            return(I_KEY);
        case 'j':
            return(J_KEY);
        case 'k':
            return(K_KEY);
        case 'l':
            return(L_KEY);
        case 'm':
            return(M_KEY);
        case 'n':
            return(N_KEY);
        case 'o':
            return(O_KEY);
        case 'p':
            return(P_KEY);
        case 'q':
            return(Q_KEY);
        case 'r':
            return(R_KEY);
        case 's':
            return(S_KEY);
        case 't':
            return(T_KEY);
        case 'u':
            return(U_KEY);
        case 'v':
            return(V_KEY);
        case 'w':
            return(W_KEY);
        case 'x':
            return(X_KEY);
        case 'y':
            return(Y_KEY);
        case 'z':
            return(Z_KEY);
        case KEY_BACKSPACE:
            return (RETURN);
        case 27:
            return (EXIT);
        default:
            return (NO_EVENT);
        }
    return (NO_EVENT);
}

bool NcurseLib::isOpen() const
{
    return _open;
}


void NcurseLib::destroyWindow() {
    _open = false;
    endwin();
}

void NcurseLib::initWindow() 
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, true);
    start_color();
    getmaxyx(stdscr, _maxheight, _maxwidth);
    _open = true;
}

NcurseLib::NcurseLib()
{
}

NcurseLib::~NcurseLib()
{
}