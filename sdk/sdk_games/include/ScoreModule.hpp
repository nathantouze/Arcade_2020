/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** ScoreModule
*/

#ifndef SCOREMODULE_HPP_
#define SCOREMODULE_HPP_

#include <string>
#include <map>
#include <unordered_map>
#include "FileManager.hpp"

namespace ScoreModule {

    void encryptScore(const std::string &gameName, const std::string &playerName, int playerScore);
    const std::unordered_map<std::string, int> getScoreOfGame(const std::string &gameName);

}
std::string encryptNumber(int number);
int decryptNumber(const std::string &number);
std::vector<std::string> splitWithChar(const std::string &string, char c);

#endif /* !SCOREMODULE_HPP_ */
