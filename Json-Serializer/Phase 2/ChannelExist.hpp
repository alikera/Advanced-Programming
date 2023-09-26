#ifndef CHANNELEXIST_HPP
#define CHANNELEXIST_HPP
#include <exception>
#define CHANNEL_EXIST "Channel already exists\n"

class ChannelExist : public std::exception
{
    const char* what() const throw()
    {
        return CHANNEL_EXIST;
    }
};

#endif