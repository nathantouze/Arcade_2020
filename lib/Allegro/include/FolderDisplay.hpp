/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** FolderDisplay
*/

#ifndef FOLDERDISPLAY_HPP_
#define FOLDERDISPLAY_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include "AllegroText.hpp"

class FolderDisplay {
    public:
        FolderDisplay();
        void setPosOnScreen(int posX, int posY);
        int getPosCursor() const;
        void setPosCursor(int posCursor);
        bool isFolderSelected() const;
        void setAllegroText(AllegroManager::AllegroText *allegroText);
        void setFolderSelected(bool isFolderSelected);
        const std::vector<std::string> &getFiles() const;
        void setFiles(const std::vector<std::string> &files);
        void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
        void drawFolder() const;
        void drawScores() const;
        ~FolderDisplay();

    protected:
    private:
        std::vector<std::string> _files;
        std::vector<std::pair<std::string, std::string>> _scores;
        int _posCursor;
        bool _isFolderSelected;
        int _posXOnScreen;
        int _posYOnScreen;
        AllegroManager::AllegroText *_allegroText;
        std::string getScoreLine(const std::string &name, const int score) const;
        int getSpace(const std::string &name, const std::string &score) const;
};

#endif /* !FOLDERDISPLAY_HPP_ */
