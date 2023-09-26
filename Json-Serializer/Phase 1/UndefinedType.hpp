#ifndef UNDEFINEDTYPE_HPP
#define UNDEFINEDTYPE_HPP
#include <exception>
#define UNDEFINED_TYPE_ERROR "Undefined type.\n"

class UndefinedType : public std::exception
{
    const char* what() const throw()
    {
        return UNDEFINED_TYPE_ERROR;
    }
};

#endif