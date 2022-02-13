I1: command.o game_loop.o game.o graphic_engine.o space.o
	gcc -o I1 command.o game_loop.o game.o graphic_engine.o space.o
space.o: space.c space.h types.h
	gcc -c space.c
command.o: command.c command.h
	gcc -c command.c
game_loop.o: game_loop.c graphic_engine.h game.h command.h
	gcc -c game_loop.c
graphic_engine.o: graphic_engine.c libscreen.h graphic_engine.h command.h space.h types.h
	gcc -c graphic_engine.c
game.o: game.c game.h
	gcc -c game.c