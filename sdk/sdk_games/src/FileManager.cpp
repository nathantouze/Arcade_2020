/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** FileManager
*/

#include "ScoreModule/FileManager.hpp"
#include <fstream>

FileManager::FileManager(const std::string &fileName) : _fileName(fileName)
{
}

#include <iostream>
std::vector<std::string> FileManager::getFileContent() const
{
    std::vector<std::string> fileContent;
    std::string buffer;
    std::ifstream readFile(_fileName);

    if (readFile.is_open() == false)
        std::cerr << "file " << _fileName << " can't be opened" << std::endl;
    while (std::getline(readFile, buffer))
        fileContent.push_back(buffer);
    readFile.close();
    return (fileContent);
}

void FileManager::writeOnFile(const std::vector<std::string> &fileContent) const
{
    std::ofstream writeFile(_fileName);

    if (writeFile.is_open() == false)
        std::cerr << std::endl;
    for (auto it : fileContent)
        writeFile << it << std::endl;
    writeFile.close();
}

FileManager::~FileManager()
{
}
