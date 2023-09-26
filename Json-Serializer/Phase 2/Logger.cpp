#include "Logger.hpp"
#include <fstream>
using namespace std;

Logger::Logger(string file_name_)
{
    file_name = file_name_;
}
void Logger::update(string message, int& message_counter)
{
    all_messages << message << endl;
    ofstream my_file(file_name);
    my_file << all_messages.str();
}