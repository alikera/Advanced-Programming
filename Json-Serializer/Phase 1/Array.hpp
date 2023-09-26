#ifndef ARRAY_HPP 
#define ARRAY_HPP

#include "Container.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Array : public Container
{
public:
    Array(std::string key_, int id_) : Container(key_, id_) {};
    void addData(Data* newData);
    std::stringstream print();
private: 
};

typedef std::vector<Array*> arrays_t;
#endif