#ifndef NOCHANNEL_HPP
#define NOCHANNEL_HPP
#include <exception>
#define NO_CHANNEL "Channel does not exist\n"

class NoChannel : public std::exception
{
    const char* what() const throw()
    {
        return NO_CHANNEL;
    }
};

#endif