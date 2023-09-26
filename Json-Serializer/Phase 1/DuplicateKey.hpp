#ifndef DUPLICATE_KEY_HPP
#define DUPLICATE_KEY_HPP
#include <exception>
#define DUPLICATE_KEY_ERROR "Duplicate Key.\n"

class DuplicateKey : public std::exception
{
    const char* what() const throw()
    {
        return DUPLICATE_KEY_ERROR;
    }
};

#endif