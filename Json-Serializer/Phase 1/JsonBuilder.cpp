
#include <exception>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#define OBJECT_TYPE "object"
#define ARRAY_TYPE "array"
#define QUOTATION "\""
#define COLON_QUOTATION "\": "
#define FALSE 0
#define TRUE 1
#include "JsonBuilder.hpp"
#include "String.hpp"
#include "Integer.hpp"
#include "UndefinedType.hpp"
#include "InvalidId.hpp"

using namespace std;

void JsonBuilder::addObject(Object* object)
{
    objects.push_back(object);
    parentIds.push_back(object->getId());
}

void JsonBuilder::addArray(Array* array)
{
    arrays.push_back(array);
    parentIds.push_back(array->getId());
}

string JsonBuilder::createKey(string key)
{
    key.insert(0,QUOTATION);
    key += COLON_QUOTATION;

    return key;
}

bool JsonBuilder::findObjectToAddData(int parentId, Data* newData)
{
    for(int i = 0; i < objects.size(); i++)
    {
        if(parentId == objects[i]->getId())
        {
            objects[i]->addData(newData);
            return true;
        }
    }
    return false;
}

bool JsonBuilder::findArrayToAddData(int parentId, Data* newData)
{
    for(int i = 0; i < arrays.size(); i++)
    {
        if(parentId == arrays[i]->getId())
        {
            arrays[i]->addData(newData);
            return true;
        }
    }
    return false;
}

void JsonBuilder::addStringToObject(int parentId, string key, string value)
{
    key = createKey(key);
    String* newString = new String(key, value);
    if(findObjectToAddData(parentId, newString) == true)
        return;

    throw InvalidId();
}

void JsonBuilder::addStringToArray(int parentId, string value)
{
    String* newString = new String(EMPTY_KEY, value);
    if(findArrayToAddData(parentId, newString) == true)
        return;

    throw InvalidId();
}

void JsonBuilder::addIntegerToObject(int parentId, string key, int value)
{
    key = createKey(key);
    Integer* newInteger = new Integer(key, value);
    if(findObjectToAddData(parentId, newInteger) == true)
        return;

    throw InvalidId();
}

void JsonBuilder::addIntegerToArray(int parentId, int value)
{
    Integer* newInteger = new Integer(EMPTY_KEY, value);
    if(findArrayToAddData(parentId, newInteger) == true)
        return;

    throw InvalidId();
}

int JsonBuilder::addContainerToObject(int parentId, std::string key, std::string type)
{
    if(type == OBJECT_TYPE)
    {
        key = createKey(key);
        Object* newObject = new Object(key, parentIds.size());
        addObject(newObject);
        if(findObjectToAddData(parentId, newObject) == false)
            throw InvalidId();
            
        return newObject->getId();
    }
    
    else if(type == ARRAY_TYPE)
    {
        key = createKey(key);
        Array* newArray = new Array(key, parentIds.size());
        addArray(newArray);
        if(findObjectToAddData(parentId, newArray) == false)
            throw InvalidId();
            
        return newArray->getId();
    }
    else
        throw UndefinedType();
}

int JsonBuilder::addContainerToArray(int parentId, std::string type)
{
    if(type == OBJECT_TYPE)
    {
        Object* newObject = new Object(EMPTY_KEY, parentIds.size());
        addObject(newObject);
        if(findArrayToAddData(parentId, newObject) == false)
            throw InvalidId();
            
        return newObject->getId();
    }
    else if(type == ARRAY_TYPE)
    {
        Array* newArray = new Array(EMPTY_KEY, parentIds.size());
        addArray(newArray);
        if(findArrayToAddData(parentId, newArray) == false)
            throw InvalidId();
                
        return newArray->getId(); 
    }
    else
        throw UndefinedType();
}
void JsonBuilder::print(int parentId)
{
    for(int i = 0; i < objects.size(); i++)
    {
        if(parentId == objects[i]->getId())
        {
            string currentKey = objects[i]->getKey();
            objects[i]->setKey(EMPTY_KEY);
            string output = (objects[i]->print().str());
            output.erase(output.size() - 1 ,1);
            cout << output << endl;
            objects[i]->setKey(currentKey);
            return;
        }
    }
    throw InvalidId();
}
