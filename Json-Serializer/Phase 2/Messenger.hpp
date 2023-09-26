#ifndef MESSENGER_HPP
#define MESSENGER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Channel.hpp"
#include "Logger.hpp"

class Messenger
{
public:
    void get_input();
    void process_tell_command();
    void process_add_bot_command();
    void add_echo_bot();
    void add_logger_bot();
    void add_fred_bot();
    void add_librarian_bot();
    void process_add_channel_command();
    Channel* search_on_channels_exist(std::string channel_name);
    Channel* find_channel_by_name(std::string channel_name);
    void add_logger_to_all_channels_created(Logger* logger);
private:
    std::vector<Channel*> channels;
};

#endif