/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** FolderDisplay
*/

#include "FolderDisplay.hpp"

FolderDisplay::FolderDisplay() : _allegroText(NULL)
{
    _posCursor = 0;
    _isFolderSelected = false;
}

void FolderDisplay::setPosOnScreen(int posX, int posY)
{
    _posXOnScreen = posX;
    _posYOnScreen = posY;
}

int FolderDisplay::getPosCursor() const
{
    return _posCursor;
}

void FolderDisplay::setPosCursor(int posCursor)
{
    _posCursor = posCursor;
}

bool FolderDisplay::isFolderSelected() const
{
    return _isFolderSelected;
}

void FolderDisplay::setFolderSelected(bool isFolderSelected)
{
    _isFolderSelected = isFolderSelected;
}

const std::vector<std::string> &FolderDisplay::getFiles() const
{
    return _files;
}

void FolderDisplay::setFiles(const std::vector<std::string> &files)
{
    _files = files;
}

void FolderDisplay::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

void FolderDisplay::setAllegroText(AllegroManager::AllegroText *allegroText)
{
    _allegroText = allegroText;
}

void FolderDisplay::drawFolder() const
{
    int numero = 0;
    ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

    if (_isFolderSelected == true)
        color = al_map_rgb(255, 255, 0);
    if (_files.size() == 0) {
        _allegroText->drawText("./assets/BarcadeFont.ttf", 24, "No files found", color, _posXOnScreen, _posYOnScreen);
        return;
    }
    if (_posCursor == 0) {
        for (auto it : _files) {
            if (numero == 0)
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, " > " + it, color, _posXOnScreen, _posYOnScreen + numero * 70);
            else if (numero < 3)
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, it, color, _posXOnScreen, _posYOnScreen + numero * 70);
            numero++;
        }
        return;
    } else if (_posCursor == (int)(_files.size()) - 1) {
        int display = 0;
        for (auto it : _files) {
            if (numero == _posCursor - 2 || numero == _posCursor - 1) {
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, it, color, _posXOnScreen, _posYOnScreen + display * 70);
                display++;
            } else if (numero == _posCursor) {
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, " > " + it, color, _posXOnScreen, _posYOnScreen + display * 70);
                display++;
            }
            numero++;
        }
    } else {
        int display = 0;
        for (auto it : _files) {
            if (numero == _posCursor - 1) {
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, it, color, _posXOnScreen, _posYOnScreen + display * 70);
                display++;
            } else if (numero == _posCursor) {
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, " > " + it, color, _posXOnScreen, _posYOnScreen + display * 70);
                display++;
            } else if (numero == _posCursor + 1) {
                _allegroText->drawText("./assets/BarcadeFont.ttf", 24, it, color, _posXOnScreen, _posYOnScreen + display * 70);
                display++;
            }
            numero++;
        }
    }
}

void FolderDisplay::drawScores() const
{
    int numero = 0;
    for (auto it : _scores) {
        if (numero >= 5)
            return;
        _allegroText->drawText("./assets/BarcadeFont.ttf", 24, it.first, al_map_rgb(255, 255, 255), _posXOnScreen, _posYOnScreen + numero * 70);
        _allegroText->drawText("./assets/BarcadeFont.ttf", 24, it.second, al_map_rgb(255, 255, 255), _posXOnScreen + getSpace(it.first, it.second) * 24, _posYOnScreen + numero * 70);
        numero++;
    }
}

int FolderDisplay::getSpace(const std::string &name, const std::string &score) const
{
    (void)name;
    std::string nb = score;
    int nbSpace = 18 - (nb.size() - 1);

    return nbSpace;
}

std::string FolderDisplay::getScoreLine(const std::string &name, const int score) const
{
    std::string nb = std::to_string(score);
    int nbSpace = 18 - (name.size() + 1) - (nb.size() + 1);

    std::string res = name;
    while (nbSpace >= 0) {
        res += '\t';
        nbSpace -= 4;
    }
    res += nb;
    return res;
}

FolderDisplay::~FolderDisplay()
{
}
