/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroException
*/

#include "AllegroException.hpp"

namespace AllegroManager {
AllegroException::AllegroException(const std::string &message, const std::string &component) : _message(message), _component(component)
{
}

AllegroException::~AllegroException()
{
}

std::string const &AllegroException::getComponent() const
{
    return (_component);
}

const char *AllegroException::what() const noexcept
{
    return (_message.c_str());
}
}