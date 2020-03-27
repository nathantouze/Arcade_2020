/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "ILibGame.hpp"

class Snake : public ILibGame {
    public:
        Snake();
        ~Snake();
        const std::vector<Entity *> &getEntities();
        void setUsername(const std::string &username);
        void receiveEvent(Event event);
        void oneCycleLoop();
        void initGame(const std::string &username);
        void closeGame();

    protected:
    private:
        enum GameStatus { WON, LOST, IN_PROGRESS, CLOSED };
        void looseGame();
        void winGame();
        bool checkEatItself();
        void grow_up(int x, int y);
        int _loop_counter;
        int _difficulty;
        int _score;
        GameStatus _status;
        std::string _username;
        Event _current_event;
        Event _new_event;
        Entity *_map;
        Entity *_apple;
        std::vector<Entity *> _obstacles;
        std::vector<Entity *> _snake;
        std::vector<Entity *> _entities;
};

enum ApplePos {
    SET,
    NOT_SET,
    FINISHED,
};

extern "C" {
    ILibGame *entryPoint() {
        return (new Snake());
    }
}

#endif /* !SNAKE_HPP_ */
