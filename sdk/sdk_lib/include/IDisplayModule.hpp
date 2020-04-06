/*
 EPITECH PROJECT, 2020
 OOP_arcade_2019_bootstrap
 File description:
 IDisplayModule
*/

#ifndef IDISPLAYMODULEHPP
#define IDISPLAYMODULEHPP

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Entity.hpp"
#include "MenuInfo.hpp"
#include "KeyBind.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual bool isOpen() const = 0;
        virtual void drawEntity(const IEntity &ent_1) = 0;
        virtual KeyBind eventListener() = 0;
        virtual void oneCycleDisplay() = 0;
        virtual void displayMenu(const MenuInfo &menuInfo) = 0;
        virtual void oneCycleClear() = 0;
        virtual void initWindow() = 0;
        virtual void destroyWindow() = 0;
};
#endif /* !IDISPLAYMODULEHPP */
