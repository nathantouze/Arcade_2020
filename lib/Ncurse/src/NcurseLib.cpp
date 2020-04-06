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

void NcurseLib::drawLetter(const IEntity &_entity, const std::string &letter) const
{
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, letter.c_str());
}

void NcurseLib::drawGameWon() const
{
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(A_BOLD);
    attron(COLOR_PAIR(4));
    mvprintw(PADDING_HEIGHT - 2, PADDING_WIDTH + PADDING_WIDTH / 5, "GAME WON");
    attroff(COLOR_PAIR(4));
    attroff(A_BOLD);
}

void NcurseLib::drawGameLost() const
{
    init_pair(3, COLOR_RED, COLOR_BLACK);
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    mvprintw(PADDING_HEIGHT - 2, PADDING_WIDTH + PADDING_WIDTH / 5, "GAME LOST");
    attroff(COLOR_PAIR(3));
    attroff(A_BOLD);
}

void NcurseLib::drawError(const IEntity &_entity) const
{
    init_pair(6, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(6));
    mvprintw(_entity.getPosY() + PADDING_HEIGHT, _entity.getPosX() * 2 + PADDING_WIDTH, " ");
    attroff(COLOR_PAIR(6));
}

void NcurseLib::drawScore(const IEntity &_entity) const
{
    std::string score = "SCORE: ";

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    score.append(std::to_string(_entity.getPosX()));
    attron(COLOR_PAIR(1));
    mvprintw(PADDING_HEIGHT - 2, PADDING_WIDTH * 2, score.c_str());
    attroff(COLOR_PAIR(1));
}

void NcurseLib::drawEntity(const IEntity &_entity)
{
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    switch (_entity.getType()) {
        case PLAYER_1:
            drawLetter(_entity, "P");
            break;
        case ENEMY_1:
            drawLetter(_entity, "E");
            break;
        case WALL_1:
            drawLetter(_entity, "W");
            break;
        case PROJECTILE:
            drawLetter(_entity, "|");
            break;
        case WALL_2:
            attron(COLOR_PAIR(2));
            drawLetter(_entity, "W");
            attroff(COLOR_PAIR(2));
            break;
        case WALL_3:
            attron(COLOR_PAIR(3));
            drawLetter(_entity, "W");
            attroff(COLOR_PAIR(3));
            break;
        case WALL_4:
            attron(COLOR_PAIR(4));
            drawLetter(_entity, "W");
            attroff(COLOR_PAIR(4));
            break;
        case PLAYER_2:
            drawLetter(_entity, "H");
            break;
        case PLAYER_3:
            drawLetter(_entity, "B");
            break;
        case PLAYER_4:
            drawLetter(_entity, "T");
            break;
        case FLOOR:
            drawLetter(_entity, "F");
            break;
        case BONUS_1:
            attron(COLOR_PAIR(5));
            drawLetter(_entity, "B");
            attroff(COLOR_PAIR(5));
            break;
        case BONUS_2:
            attron(COLOR_PAIR(2));
            drawLetter(_entity, "B");
            attroff(COLOR_PAIR(2));
            break;
        case BONUS_3:
            attron(COLOR_PAIR(3));
            drawLetter(_entity, "B");
            attroff(COLOR_PAIR(3));
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
        default:
            break;
    }
}

void NcurseLib::oneCycleDisplay()
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

    // SCORE
    mvprintw(_maxheight / 2 + _maxheight / 12, _maxwidth / 2 - std::strlen("SCORE"), "SCORE");
    if (menu.getGameScores().size() == 0)
        mvprintw(_maxheight / 2 + _maxheight / 4, _maxwidth / 2 - std::strlen("SCORE") * 2, "No score available.");
    else {
        int index = 0;
        for (std::pair<std::string, std::string> element : menu.getGameScores()) {
            std::string score = element.first;
            score.append(": ");
            score.append(element.second);
            score.append(" points");
            mvprintw(_maxheight / 2 + _maxheight / 12 + 3 + (2 * index), _maxwidth / 2 - std::strlen("SCORE") * 2, score.c_str());
            index++;
        }
    }
    attroff(A_BOLD);
}

void NcurseLib::oneCycleClear()
{
    clear();
}

KeyBind NcurseLib::eventListener()
{
    int ch = getch();

    switch (ch) {
        case KEY_EXIT:
            return (EXIT);
        case ' ':
            return (SPACE);
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
            return(A);
        case 'b':
            return(B);
        case 'c':
            return(C);
        case 'd':
            return(D);
        case 'e':
            return(E);
        case 'f':
            return(F);
        case 'g':
            return(G);
        case 'h':
            return(H);
        case 'i':
            return(I);
        case 'j':
            return(J);
        case 'k':
            return(K);
        case 'l':
            return(L);
        case 'm':
            return(M);
        case 'n':
            return(N);
        case 'o':
            return(O);
        case 'p':
            return(P);
        case 'q':
            return(Q);
        case 'r':
            return(R);
        case 's':
            return(S);
        case 't':
            return(T);
        case 'u':
            return(U);
        case 'v':
            return(V);
        case 'w':
            return(W);
        case 'x':
            return(X);
        case 'y':
            return(Y);
        case 'z':
            return(Z);
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

extern "C" {
    IDisplayModule *entryPoint() {
        return (new NcurseLib());
    }
}