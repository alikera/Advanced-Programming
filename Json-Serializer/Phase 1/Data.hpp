#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define COMMA ','

class Data
{
public:
    Data(std::string key_);
    std::string getKey() { return key; }
    virtual std::stringstream print() = 0;
protected:
    std::string key;
};

typedef std::vector<Data*> datas_t;

#endif