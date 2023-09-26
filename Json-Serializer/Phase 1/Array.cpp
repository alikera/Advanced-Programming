#include "Array.hpp"
using namespace std;
#define OPEN_AND_CLOSE_SQUARE_BRKT "[],"
#define OPEN_SQUARE_BRKT "["
#define CLOSE_SQUARE_BRKT "],"

void Array::addData(Data* newData)
{
    datas.push_back(newData);
}
stringstream Array::print()
{
    stringstream ssJson;
    ssJson << key;
    if(datas.size() == 0)
    {
        ssJson << OPEN_AND_CLOSE_SQUARE_BRKT;
        return ssJson;
    }
    ssJson << OPEN_SQUARE_BRKT << endl;
    ssJson << createDatasInsideContainer();      
    ssJson << createLastDataOfContainer() << endl;
    ssJson << CLOSE_SQUARE_BRKT;
    return ssJson;
}
