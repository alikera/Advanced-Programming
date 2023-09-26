all: Goodreads.out

Goodreads.out: main.o GoodReads.o Users.o Authors.o Books.o Reviews.o Functions.o 
	g++ -std=c++11 main.o GoodReads.o Users.o Authors.o Books.o Reviews.o Functions.o -o Goodreads.out

main.o: main.cpp GoodReads.hpp Functions.hpp
	g++ -std=c++11 -c main.cpp

GoodReads.o: GoodReads.cpp GoodReads.hpp Users.hpp Authors.hpp Books.hpp Reviews.hpp
	g++ -std=c++11 -c GoodReads.cpp

Users.o: Users.cpp Users.hpp Books.hpp Reviews.hpp
	g++ -std=c++11 -c Users.cpp

Authors.o: Authors.cpp Authors.hpp Books.hpp Reviews.hpp
	g++ -std=c++11 -c Authors.cpp

Books.o: Books.cpp Books.hpp Reviews.hpp 
	g++ -std=c++11 -c Books.cpp 

Reviews.o: Reviews.cpp Reviews.hpp
	g++ -std=c++11 -c Reviews.cpp

Functions.o: Functions.cpp Functions.hpp 
	g++ -std=c++11 -c Functions.cpp

clean:
	rm *.o
	rm Goodreads.out


