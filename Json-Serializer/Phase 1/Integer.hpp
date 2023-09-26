#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

class Integer : public Data
{
public:
    Integer(std::string key_, int value_) : Data(key_) 
    {
        value = value_;
    }
    std::stringstream print();
private:
    int value;
};

#endif