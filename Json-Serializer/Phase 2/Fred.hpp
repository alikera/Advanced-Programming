#ifndef FRED_HPP
#define FRED_HPP

#include "Observer.hpp"
#include <iostream>
#include <string>

class Channel;

class Fred : public Observer
{
public:
    Fred(Channel* channel);
    void update(std::string message, int& message_counter);
private:
    Channel* src_channel;
};

#endif