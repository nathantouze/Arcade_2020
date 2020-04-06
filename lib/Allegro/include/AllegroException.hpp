/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroException
*/

#ifndef ALLEGROEXCEPTION_HPP_
#define ALLEGROEXCEPTION_HPP_

#include <exception>
#include <string>

namespace AllegroManager {
class AllegroException : public std::exception {
    public:
        AllegroException(std::string const &message, std::string const &component = "Unknown");
        std::string const &getComponent() const;
        const char *what() const noexcept override;
        ~AllegroException();

    protected:
    private:
        std::string _message;
        std::string _component;
};
}

#endif /* !ALLEGROEXCEPTION_HPP_ */
