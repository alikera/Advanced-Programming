#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "Observer.hpp"
#include <iostream>
#include <string>
#include <sstream>


class Logger : public Observer
{
public:
    Logger(std::string file_name_);
    void update(std::string message, int& message_counter);
private:
    std::string file_name;
    std::stringstream all_messages;
};

#endif