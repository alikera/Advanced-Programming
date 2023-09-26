#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>
#include <string>

class Observer
{
public:
    virtual void update(std::string message, int& message_counter) = 0;
};

#endif