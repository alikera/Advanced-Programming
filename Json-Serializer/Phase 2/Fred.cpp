#include "Fred.hpp"
#include "Channel.hpp"
#define FREDS_SENSETIVE_WORD "Hi"
#define FREDS_ANSWER "Hello"

using namespace std;

Fred::Fred(Channel* channel)
{
    src_channel = channel;
}
void Fred::update(string message, int& message_counter)
{
    if(message == FREDS_SENSETIVE_WORD)
        src_channel->notify_observers(FREDS_ANSWER);
}