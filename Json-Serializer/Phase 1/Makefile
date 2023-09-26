CC := g++ -std=c++11
obj_files = main.o JsonBuilder.o Data.o Container.o Array.o Object.o String.o Integer.o

all: 1.out

1.out: ${obj_files}
	$(CC) ${obj_files} -o 1.out

main.o: main.cpp JsonBuilder.hpp Object.hpp Array.hpp Container.hpp Data.hpp InvalidId.hpp UndefinedType.hpp DuplicateKey.hpp
	$(CC) -c main.cpp -o main.o

JsonBuilder.o: JsonBuilder.cpp JsonBuilder.hpp Object.hpp Array.hpp Container.hpp Data.hpp String.hpp Integer.hpp InvalidId.hpp UndefinedType.hpp DuplicateKey.hpp
	$(CC) -c JsonBuilder.cpp -o JsonBuilder.o

Object.o: Object.cpp Object.hpp Container.hpp Data.hpp DuplicateKey.hpp
	$(CC) -c Object.cpp -o Object.o

Array.o: Array.cpp Array.hpp Container.hpp Data.hpp
	$(CC) -c Array.cpp -o Array.o

Container.o: Container.cpp Container.hpp Data.hpp
	$(CC) -c Container.cpp -o Container.o

String.o: String.cpp String.hpp Data.hpp
	$(CC) -c String.cpp -o String.o

Integer.o: Integer.cpp Integer.hpp Data.hpp
	$(CC) -c Integer.cpp -o Integer.o

Data.o: Data.cpp Data.hpp
	$(CC) -c Data.cpp -o Data.o

.PHONY: clean
clean:
	rm -r *.o