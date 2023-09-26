CC := clang++
CCFLAGS += -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer
obj_files = main.o FieldRunners.o rsdl.o Tower.o Enemy.o Missile.o Glue.o Gattling.o Tesla.o Bullet.o functions.o Scrambler.o TheRunner.o StubbornRunner.o SuperTrooper.o

all: FieldRunners.out

FieldRunners.out: ${obj_files}
	$(CC) ${obj_files} $(CCFLAGS) -o FieldRunners.out

main.o: rsdl.hpp main.cpp FieldRunners.hpp
	$(CC) -c main.cpp -o main.o

FieldRunners.o: FieldRunners.cpp FieldRunners.hpp Tower.hpp functions.hpp Gattling.hpp Tesla.hpp Missile.hpp Glue.hpp Enemy.hpp Scrambler.hpp TheRunner.hpp StubbornRunner.hpp SuperTrooper.hpp rsdl.hpp
	$(CC) -c FieldRunners.cpp -o FieldRunners.o

Gattling.o: Gattling.cpp Gattling.hpp Tower.hpp Bullet.hpp Enemy.hpp
	$(CC) -c Gattling.cpp -o Gattling.o

Tesla.o: Tesla.cpp Tesla.hpp Tower.hpp Bullet.hpp Enemy.hpp
	$(CC) -c Tesla.cpp -o Tesla.o

Missile.o: Missile.cpp Missile.hpp Tower.hpp Bullet.hpp Enemy.hpp
	$(CC) -c Missile.cpp -o Missile.o

Glue.o: Glue.cpp Glue.hpp Tower.hpp Bullet.hpp Enemy.hpp
	$(CC) -c Glue.cpp -o Glue.o

Tower.o: Tower.cpp Tower.hpp Enemy.hpp Bullet.hpp functions.hpp Enemy.hpp rsdl.hpp
	$(CC) -c Tower.cpp -o Tower.o

Bullet.o: Bullet.cpp Bullet.hpp Enemy.hpp
	$(CC) -c Bullet.cpp -o Bullet.o

TheRunner.o: TheRunner.cpp TheRunner.hpp Enemy.hpp
	$(CC) -c TheRunner.cpp -o TheRunner.o

Scrambler.o: Scrambler.cpp Scrambler.hpp Enemy.hpp
	$(CC) -c Scrambler.cpp -o Scrambler.o

SuperTrooper.o: SuperTrooper.cpp SuperTrooper.hpp Enemy.hpp
	$(CC) -c SuperTrooper.cpp -o SuperTrooper.o

StubbornRunner.o: StubbornRunner.cpp StubbornRunner.hpp Enemy.hpp
	$(CC) -c StubbornRunner.cpp -o StubbornRunner.o

Enemy.o: Enemy.cpp Enemy.hpp rsdl.hpp
	$(CC) -c Enemy.cpp -o Enemy.o

functions.o: functions.cpp functions.hpp
	$(CC) -c functions.cpp -o functions.o
    
rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o