#include "Container.hpp"
using namespace std;
#define TAB "    "

Container::Container(std::string key_, int id_) : Data(key_) 
    {
        id = id_;
    }

void Container::setKey(string key_)
{
    key = key_;
}
string Container::createDatasInsideContainer()
{
    stringstream ssJason;
    for(int i = 0; i < datas.size() - 1; i++)
        ssJason << tabEachLineOfData(datas[i]->print()).str();

    return ssJason.str();
}

stringstream Container::tabEachLineOfData(stringstream eachData)
{
    string eachLine;
    stringstream newData;
    for(int j = 0 ; getline(eachData, eachLine) ; j++)
    {	
        eachLine.insert(0, TAB);
        newData << eachLine << endl;
    }
    return newData;
}

string Container::createLastDataOfContainer()
{
    string lastData = tabEachLineOfData(datas[datas.size() - 1]->print()).str();
    lastData.erase(lastData.size() - 2 ,2);

    return lastData;
}
