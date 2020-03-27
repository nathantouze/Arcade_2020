/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoreManager
*/

#ifndef SCOREMANAGER_HPP_
#define SCOREMANAGER_HPP_

#include <string>

class ScoreManager {
    public:
        ScoreManager();
        void saveScore(const std::string &playerName) const;
        void resetScore();
        void breakMushroom();
        void resetMushroom();
        void breakSpider();
        void breakCentipede();
        void centiOnBot();
        int getScore() const;
        ~ScoreManager();

    protected:
    private:
        int _score;
};

#endif /* !SCOREMANAGER_HPP_ */
