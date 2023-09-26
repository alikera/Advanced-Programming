CC := g++ -std=c++11
obj_files = main.o Messenger.o Channel.o Echo.o Logger.o Fred.o Librarian.o

all: 2.out

2.out: ${obj_files}
	$(CC) ${obj_files} -o 2.out

main.o: main.cpp Messenger.hpp Channel.hpp Logger.hpp Observer.hpp
	$(CC) -c main.cpp -o main.o

Messenger.o: Messenger.cpp Messenger.hpp Channel.hpp Logger.hpp Observer.hpp NoChannel.hpp SameChannel.hpp ChannelExist.hpp
	$(CC) -c Messenger.cpp -o Messenger.o

Echo.o: Echo.cpp Echo.hpp Observer.hpp Channel.hpp
	$(CC) -c Echo.cpp -o Echo.o

Logger.o: Logger.cpp Logger.hpp Observer.hpp Channel.hpp
	$(CC) -c Logger.cpp -o Logger.o

Fred.o: Fred.cpp Fred.hpp Observer.hpp Channel.hpp
	$(CC) -c Fred.cpp -o Fred.o

Librarian.o: Librarian.cpp Librarian.hpp Observer.hpp Channel.hpp
	$(CC) -c Librarian.cpp -o Librarian.o

Channel.o: Channel.cpp Channel.hpp Observer.hpp Channel.hpp
	$(CC) -c Channel.cpp -o Channel.o

.PHONY: clean
clean:
	rm -r *.o