#ifndef SAMECHANNEL_HPP
#define SAMECHANNEL_HPP
#include <exception>
#define SAME_CHANNEL "Source and destination cannot be the same channel\n"

class SameChannel : public std::exception
{
    const char* what() const throw()
    {
        return SAME_CHANNEL;
    }
};

#endif