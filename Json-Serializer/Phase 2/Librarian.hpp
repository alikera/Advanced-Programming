#ifndef LIBRARIAN_HPP
#define LIBRARIAN_HPP

#include "Observer.hpp"
#include <iostream>
#include <string>

class Channel;

class Librarian : public Observer
{
public:
    Librarian(Channel* channel);
    void update(std::string message, int& message_counter);
private:
    Channel* src_channel;
};

#endif