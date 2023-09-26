#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

class Container : public Data
{
public:
    Container(std::string key_, int id_);
    int getId() { return id; }
    std::string createDatasInsideContainer(); 
    std::stringstream tabEachLineOfData(std::stringstream eachData);
    std::string createLastDataOfContainer();
    virtual void addData(Data* newData) = 0;
    void setKey(std::string key_);
protected:
    int id;
    datas_t datas;
};

#endif