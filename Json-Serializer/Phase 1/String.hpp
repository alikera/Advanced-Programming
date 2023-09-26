#ifndef STRING_HPP
#define STRING_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

class String : public Data
{
public:
    String(std::string key_, std::string value_) : Data(key_) 
    {
        value = value_;
    }
    std::stringstream print();
private:
    std::string value;
};

#endif