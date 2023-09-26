#include "Librarian.hpp"
#include "Channel.hpp"

#define LIBRARIAN_RESPONSE "Quiet!"
#define LIBRARIAN_SENSETIVE_COUNTER 5
using namespace std;

Librarian::Librarian(Channel* channel)
{
    src_channel = channel;
}
void Librarian::update(string message, int& message_counter)
{
    if(message_counter >= LIBRARIAN_SENSETIVE_COUNTER)
    {
        message_counter -= LIBRARIAN_SENSETIVE_COUNTER;
        src_channel->notify_observers(LIBRARIAN_RESPONSE);
    }
    
}