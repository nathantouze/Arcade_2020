/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** DLLoaderException
*/

#include "DLLoaderException.hpp"

DLLoaderException::DLLoaderException(const std::string &message, const std::string &component) : _message(message), _component(component)
{}

DLLoaderException::~DLLoaderException()
{}

std::string const &DLLoaderException::getComponent() const
{
    return (_component);
}

const char *DLLoaderException::what() const noexcept
{
    return (_message.c_str());
}