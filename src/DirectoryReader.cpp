/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** DirectoryReader
*/

#include "DirectoryReader.hpp"
#include <dirent.h>
#include <algorithm>

DirectoryReader::DirectoryReader(const std::string &directoryName) : _directoryName(directoryName)
{
}

bool DirectoryReader::isDirectoryExists() const
{
    DIR *dir;

    if ((dir = opendir(_directoryName.c_str())) == NULL)
        return (false);
    closedir(dir);
    return (true);
}

void DirectoryReader::reloadList()
{
    DIR *dir;
    struct dirent *ent;

    _list.clear();
    if ((dir = opendir(_directoryName.c_str())) == NULL)
        return;
    while ((ent = readdir(dir)) != NULL)
        _list.push_back(ent->d_name);
    closedir(dir);
}

const std::vector<std::string> &DirectoryReader::getList() const
{
    return _list;
}

bool DirectoryReader::isFileExists(const std::string &fileName) const
{
    if (std::find(_list.begin(), _list.end(), fileName) != _list.end())
        return (true);
    return (false);
}

DirectoryReader::~DirectoryReader()
{
}
