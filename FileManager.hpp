/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** FileManager
*/

#ifndef FILEMANAGER_HPP_
#define FILEMANAGER_HPP_

#include "string"
#include <vector>

class FileManager {
    public:
        FileManager(const std::string &fileName);
        std::vector<std::string> getFileContent() const;
        void writeOnFile(const std::vector<std::string> &fileContent) const;
        ~FileManager();

    protected:
    private:
        std::string _fileName;
};

#endif /* !FILEMANAGER_HPP_ */
