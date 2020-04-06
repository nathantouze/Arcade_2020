/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroLib
*/

#ifndef ALLEGROLIB_HPP_
#define ALLEGROLIB_HPP_

#include "IDisplayModule.hpp"
#include "TypeEntity.hpp"
#include "KeyBind.hpp"
#include "Entity.hpp"
#include "FolderDisplay.hpp"
#include "AllegroManager.hpp"
#include "AllegroEvent.hpp"
#include "AllegroText.hpp"
#include "AllegroPicture.hpp"

class AllegroLib : public IDisplayModule {
    public:
        AllegroLib();
        ~AllegroLib();
        bool isOpen() const;
        void drawEntity(const IEntity &entity);
        KeyBind eventListener();
        void oneCycleDisplay();
        void displayMenu(const MenuInfo &menu);
        void oneCycleClear();
        void initWindow();
        void destroyWindow();

    protected:
    private:
        bool _isOpen;
        FolderDisplay _graphFolder;
        FolderDisplay _gamesFolder;
        FolderDisplay _scoresFolder;
        AllegroManager::AllegroManager _allegroManager;
        AllegroManager::AllegroEvent _allegroEvent;
        AllegroManager::AllegroText _allegroText;
        AllegroManager::AllegroPicture _allegroPicture;
        int _maxXMap;
        int _maxYMap;
        KeyBind analyseKeyboardEvent(ALLEGRO_EVENT *event) const;
        int getPosOnWindow(int windowSize, int mapSize, int posOnMap);
        void displayEntityWithAllegro(TypeEntity type, int posX, int posY);
};

extern "C" {
    IDisplayModule *entryPoint() {
        return (new AllegroLib());
    }
}

#endif /* !ALLEGROLIB_HPP_ */
