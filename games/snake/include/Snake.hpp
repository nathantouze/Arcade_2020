/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGameModule.hpp"
#include <vector>

class Snake : public IGameModule {
    public:
        Snake();
        ~Snake();
        void receiveEvent(KeyBind key);
        const std::vector<IEntity *> &getEntities();
        bool oneCycleLoop();
        int getScore() const;
        void initGame();
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
        KeyBind _current_event;
        KeyBind _new_event;
        Entity *_map;
        Entity *_apple;
        std::vector<IEntity *> _obstacles;
        std::vector<IEntity *> _snake;
        std::vector<IEntity *> _entities;
};

enum ApplePos {
    SET,
    NOT_SET,
    FINISHED,
};

extern "C" {
    IGameModule *entryPoint() {
        return (new Snake());
    }
}

#endif /* !SNAKE_HPP_ */
