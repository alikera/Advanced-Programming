#include "String.hpp"
using namespace std;
#define QUOTATION "\""

stringstream String::print()
{
    stringstream ssJson;
    ssJson << key << QUOTATION << value << QUOTATION << COMMA;
    return ssJson;
}