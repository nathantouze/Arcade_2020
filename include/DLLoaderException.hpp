/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** DLLoaderException
*/

#ifndef DLLOADEREXCEPTION_HPP_
#define DLLOADEREXCEPTION_HPP_

#include <exception>
#include <string>

class DLLoaderException : public std::exception {
    public:
        DLLoaderException(std::string const &message, std::string const &component = "Unknown");
        std::string const &getComponent() const;
        const char *what() const noexcept override;
        ~DLLoaderException();

    protected:
    private:
        std::string _message;
        std::string _component;
};

#endif /* !DLLOADEREXCEPTION_HPP_ */
