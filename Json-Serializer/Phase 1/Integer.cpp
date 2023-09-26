#include "Integer.hpp"
using namespace std;

stringstream Integer::print()
{
    stringstream ssJson;
    ssJson << key << value << COMMA;
    return ssJson;
}