/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by ntouze,
*/
#ifndef OOP_ARCADE_2019_MENUINFO_HPP
#define OOP_ARCADE_2019_MENUINFO_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

class MenuInfo {
    public:
    /* Constructor */
    MenuInfo();
    /* Destructor */
    ~MenuInfo();
    /* Getter */
    const std::vector<std::string> &getGraphList() const;
    const std::vector<std::string> &getGameList() const;
    const std::unordered_map<std::string, int> &getGameScores() const;
    const int &getGraphIdx() const;
    const int &getGameIdx() const;
    const int &getActiveBoxIdx() const;
    const std::string &getPlayerName() const;
    /* Setter */
    void setGraphList(std::vector<std::string> graphList);
    void setGameList(std::vector<std::string> gameList);
    void setGameScores(std::unordered_map<std::string, int> gameScores);
    void setGraphIdx(int graphIdx);
    void setGameIdx(int gameIdx);
    void setActiveBoxIdx(int activeBoxIdx);
    void setPlayerName(const std::string &playerName);
    protected:
    private:
    std::vector<std::string> _graphList;
    std::vector<std::string> _gameList;
    std::unordered_map<std::string, int> _gameScores;
    int _graphIdx{};
    int _gameIdx{};
    int _activeBoxIdx{};
    std::string _playerName;
};

#endif //OOP_ARCADE_2019_MENUINFO_HPP
