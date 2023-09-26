#include "Messenger.hpp"
#include "Fred.hpp"
#include "Librarian.hpp"
#include "Echo.hpp"
#include <exception>
#include "NoChannel.hpp"
#include "SameChannel.hpp"
#include "ChannelExist.hpp"
#define TELL_COMMAND "tell"
#define ADD_BOT_COMMAND "add_bot"
#define ADD_CHANNEL_COMMAND "add_channel"
#define ECHO_NAME "echo"
#define LOGGER_NAME "logger"
#define FRED_NAME "fred"
#define LIBRARIAN_NAME "librarian"


using namespace std;

void Messenger::get_input()
{
    string command;
    while(cin >> command)
    {
        try
        {
            if(command == TELL_COMMAND)
                process_tell_command();
                
            if(command == ADD_BOT_COMMAND)
                process_add_bot_command();
            
            if(command == ADD_CHANNEL_COMMAND)
                process_add_channel_command();
                
        }catch(exception& ex)
        {
            cerr << ex.what();
        }
    }
    
}
void Messenger::process_tell_command()
{
    string channel_name;
    cin >> channel_name;
    string message;
    getline(cin >> ws, message);
    Channel* channel_to_send_message = find_channel_by_name(channel_name);
    channel_to_send_message->notify_observers(message);
}
Channel* Messenger::search_on_channels_exist(string channel_name)
{
    for(int i = 0; i < channels.size(); i++)
        if(channels[i]->get_channel_name() == channel_name)
            return channels[i];
    return NULL;
}
Channel* Messenger::find_channel_by_name(string channel_name)
{
    Channel* found_channel = search_on_channels_exist(channel_name);
    if(found_channel == NULL)
        throw NoChannel();
        
    return found_channel;
}
void Messenger::add_logger_to_all_channels_created(Logger* logger)
{
    if(channels.size() == 0)
        throw NoChannel();
        
    for(int i = 0; i < channels.size(); i++)
        channels[i]->register_logger(logger);
}

void Messenger::process_add_bot_command()
{
    string bot_name;
    cin >> bot_name;
    if(bot_name == ECHO_NAME)
        add_echo_bot();
        
    if(bot_name == LOGGER_NAME)
        add_logger_bot();
        
    if(bot_name == FRED_NAME)
        add_fred_bot();
        
    if(bot_name == LIBRARIAN_NAME)
        add_librarian_bot();
}
void Messenger::add_echo_bot()
{
    string src_channel_name, dest_channel_name;
    cin >> src_channel_name >> dest_channel_name;
    if(src_channel_name == dest_channel_name)
        throw SameChannel();
        
    Channel* src_channel = find_channel_by_name(src_channel_name);
    Channel* dest_channel = find_channel_by_name(dest_channel_name);
    Echo* new_echo = new Echo(src_channel, dest_channel);
    
    src_channel->register_observer(new_echo);
}
void Messenger::add_logger_bot()
{
    string file_name;
    getline(cin >> ws, file_name);
    Logger* new_logger = new Logger(file_name);
    add_logger_to_all_channels_created(new_logger);
}
void Messenger::add_fred_bot()
{
    string channel_name;
    cin >> channel_name;
    Channel* src_channel = find_channel_by_name(channel_name);
    Fred* new_fred = new Fred(src_channel);
    src_channel->register_observer(new_fred);
}
void Messenger::add_librarian_bot()
{
    string channel_name;
    cin >> channel_name;
    Channel* src_channel = find_channel_by_name(channel_name);
    Librarian* new_librarian = new Librarian(src_channel);
    src_channel->register_observer(new_librarian);
}
void Messenger::process_add_channel_command()
{
    string channel_name;
    cin >> channel_name;
    if(search_on_channels_exist(channel_name) != NULL)
        throw ChannelExist();
        
    Channel* new_channel = new Channel(channel_name);
    channels.push_back(new_channel);
}