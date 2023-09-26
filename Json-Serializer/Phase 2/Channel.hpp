#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Observer.hpp"
#include "Logger.hpp"

class Channel
{
public:
    Channel(std::string channel_name);
    void register_observer(Observer* observer);
    void register_logger(Logger* logger);
    void notify_observers(std::string message);
    std::string get_channel_name() { return name; }
private:
    std::string name;
    std::string current_message;
    std::vector<Observer*> observers;
    int message_counter = 0;
};

#endif