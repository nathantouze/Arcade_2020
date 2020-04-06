/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by jserenne,
*/

#include "Music.hpp"

/* Constructor */

Music::Music()
{
    _isLoad = false;
}

Music::Music(std::string filepath)
{
    if (!_music.openFromFile(filepath))
        _isLoad = false;
    else
        _isLoad = true;
}

/* Destructor */

Music::~Music()
{
}

/* Music management */

void Music::play()
{
    if (!_isLoad && _music.getStatus() == sf::Music::Stopped)
        return ;
    _music.play();
}

void Music::pause()
{
    if (!_isLoad && _music.getStatus() == sf::Music::Playing)
        return ;
    _music.pause();
}

void Music::stop()
{
    if (!_isLoad && _music.getStatus() == sf::Music::Playing)
        return ;
    _music.stop();
}

void Music::loadMusic(std::string filepath)
{
    if (!_music.openFromFile(filepath))
        _isLoad = false;
    else
        _isLoad = true;
}