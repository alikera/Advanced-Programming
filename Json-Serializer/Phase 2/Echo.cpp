#include "Echo.hpp"
#include "Channel.hpp"

using namespace std;

Echo::Echo(Channel* src_channel_, Channel* dest_channel_)
{
    src_channel = src_channel_;
    dest_channel = dest_channel_;
}
void Echo::update(string message, int& message_counter)
{
    dest_channel->notify_observers(message);
}