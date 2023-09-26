#ifndef OBJECT_HPP 
#define OBJECT_HPP

#include "Container.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Object : public Container
{
public:
    Object(const std::string& key_, const int& id_) : Container(key_, id_) {};
    bool checkForDuplicateKey(Data* newData);
    void addData(Data* newData);
    std::stringstream print();
private:

};

typedef std::vector<Object*> objects_t;
#endif