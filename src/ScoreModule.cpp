/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** ScoreModule
*/

#include "ScoreModule/ScoreModule.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

void ScoreModule::encryptScore(const std::string &gameName, const std::string &playerName, int playerScore)
{
    FileManager file("assets/.res.son");
    std::vector<std::string> fileContent;
    std::vector<std::string> newFileContent;
    bool find = false;
    std::string searchString(gameName + " " + playerName);

    try {
        fileContent = file.getFileContent();
        for (auto it : fileContent) {
            if (it.substr(0, searchString.size()) == searchString) {
                find = true;
                if (decryptNumber(it.substr(searchString.size() + 1, it.size() - 1)) < playerScore)
                    newFileContent.push_back(searchString + " " + encryptNumber(playerScore));
                else
                    newFileContent.push_back(it);
            } else
                newFileContent.push_back(it);
        }
        if (find == false)
            newFileContent.push_back(searchString + " " + encryptNumber(playerScore));
        file.writeOnFile(newFileContent);
    } catch (std::exception &e) {

    }
}

bool sortScore(std::pair<std::string, std::string> i, std::pair<std::string, std::string> j) 
{ 
    return (stoi(i.second) > stoi(j.second));
}

const std::vector<std::pair<std::string, std::string>> ScoreModule::getScoreOfGame(const std::string &gameName)
{
    std::vector<std::pair<std::string, std::string>> mapScore;
    FileManager file("assets/.res.son");
    
    try {
        std::vector<std::string> fileContent = file.getFileContent();
        for (auto it : fileContent) {
            if (it.substr(0, gameName.size()) == gameName) {
                std::vector<std::string> stringCut = splitWithChar(it, ' ');
                if (stringCut[0] == gameName)
                    mapScore.push_back({stringCut[1], stringCut[2]});
            }
        }
        std::sort(mapScore.begin(), mapScore.end(), sortScore);

    } catch (std::exception &e) {

    }
    return (mapScore);
}

std::vector<std::string> splitWithChar(const std::string &string, char c)
{
    std::vector<std::string> vector;

    std::stringstream ss(string);
    std::string item;
    while (std::getline(ss, item, c)) {
        if (item != "")
            vector.push_back(item);
    }
    return (vector);
}

std::string encryptNumber(int number)
{
    return (std::to_string(number));
}

int decryptNumber(const std::string &number)
{
    return (stoi(number));
}