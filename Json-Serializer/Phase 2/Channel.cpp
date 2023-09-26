#include "Channel.hpp"
using namespace std;

Channel::Channel(string channel_name)
{
    name = channel_name;
}
void Channel::register_observer(Observer* observer)
{
    observers.push_back(observer);
}
void Channel::register_logger(Logger* logger)
{
    observers.insert(observers.begin(), logger);
}
void Channel::notify_observers(string message)
{
    message_counter++;
    for(int i = 0; i < observers.size(); i++)
        observers[i]->update(message, message_counter);
}