#ifndef JSONBUILDER_HPP
#define JSONBUILDER_HPP

#include "Object.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>
#include <vector>
#define EMPTY_KEY ""

class JsonBuilder
{
public:
    JsonBuilder() : mother(EMPTY_KEY, 0) { addObject(&mother); }

    void addStringToObject(int parentId, std::string key, std::string value);
    void addIntegerToObject(int parentId, std::string key, int value);
    int addContainerToObject(int parentId, std::string key, std::string type);
    void addStringToArray(int parentId, std::string value);
    void addIntegerToArray(int parentId, int value);
    int addContainerToArray(int parentId, std::string type);
    void print(int id);
    
    bool findObjectToAddData(int parentId, Data* newData);
    bool findArrayToAddData(int parentId, Data* newData);
    void addObject(Object* object);
    void addArray(Array* array);
    std::string createKey(std::string key);
private:
    Object mother;
    objects_t objects;
    arrays_t arrays;
    std::vector<int> parentIds;
};

#endif