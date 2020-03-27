/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** DirectoryReader
*/

#ifndef DIRECTORYREADER_HPP_
#define DIRECTORYREADER_HPP_

#include <vector>
#include <string>

class DirectoryReader {
    public:
        DirectoryReader(const std::string &directoryName);
        bool isDirectoryExists() const;
        void reloadList();
        bool isFileExists(const std::string &fileName) const;
        const std::vector<std::string> &getList() const;
        ~DirectoryReader();

    protected:
    private:
        std::string _directoryName;
        std::vector<std::string> _list;
};

#endif /* !DIRECTORYREADER_HPP_ */
