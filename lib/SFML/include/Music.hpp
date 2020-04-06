/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by jserenne,
*/

#ifndef OOP_ARCADE_2019_MUSIC_HPP
#define OOP_ARCADE_2019_MUSIC_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Music {
    public:
        /* Constructor */
        Music();
        Music(std::string filepath);
        /* Destructor */
        ~Music();
        /* Window management */
        bool isPlaying() const;
        void play();
        void pause();
        void stop();
        void loadMusic(std::string filepath);

    private:
        sf::Music _music;
        bool _isLoad;
};

#endif //OOP_ARCADE_2019_MUSIC_HPP