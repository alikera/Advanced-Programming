#ifndef ECHO_HPP
#define ECHO_HPP

#include "Observer.hpp"
#include <iostream>
#include <string>

class Channel;

class Echo : public Observer
{
public:
    Echo(Channel* src_channel_, Channel* dest_channel_);
    void update(std::string message, int& message_counter);
private:
    Channel* src_channel;
    Channel* dest_channel;
};

#endif