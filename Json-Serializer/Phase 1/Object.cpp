#include "Object.hpp"
#include "DuplicateKey.hpp"
#define OPEN_AND_CLOSE_CURLY_BRKT "{},"
#define OPEN_CURLY_BRKT "{"
#define CLOSE_CURLY_BRKT "},"

using namespace std;

void Object::addData(Data* newData)
{
    checkForDuplicateKey(newData);
    datas.push_back(newData);
}

bool Object::checkForDuplicateKey(Data* newData)
{
    for(int i = 0; i < datas.size(); i++)
        if(datas[i]->getKey() == newData->getKey())
            throw DuplicateKey();
}

stringstream Object::print()
{
    stringstream ssJson;
    ssJson << key;
    if(datas.size() == 0)
    {
        ssJson << OPEN_AND_CLOSE_CURLY_BRKT;
        return ssJson;
    }
    ssJson << OPEN_CURLY_BRKT << endl;
    ssJson << createDatasInsideContainer();    
    ssJson << createLastDataOfContainer() << endl;
    ssJson << CLOSE_CURLY_BRKT;
    return ssJson;
}
