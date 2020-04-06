/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "IDisplayModule.hpp"
#include "DLLoader.hpp"
#include "Entity.hpp"
#include "Core.hpp"
#include "MenuInfo.hpp"

void print_usage()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "\t./arcade [graphical_lib_name.so]" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2 || strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) {
        print_usage();
        return (84);
    }
    try {
        DLLoader<IDisplayModule> lib = DLLoader<IDisplayModule>(av[1]);
        IDisplayModule *libGraphical = lib.getInstance("entryPoint");
        Core core(libGraphical);
        core.loopCore();
    } catch (DLLoaderException &e) {
        std::cerr << e.getComponent() << " : " << e.what() << std::endl;
        return (84);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}