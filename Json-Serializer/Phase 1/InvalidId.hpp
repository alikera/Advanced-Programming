#ifndef INVALIDID_HPP
#define INVALIDID_HPP
#include <exception>
#define INVALID_ID_ERROR "Invalid id.\n"

class InvalidId : public std::exception
{
    const char* what() const throw()
    {
        return INVALID_ID_ERROR;
    }
};

#endif