All: I1 clean programa
I1: command.o game_loop.o game.o graphic_engine.o space.o game_reader.o player.o object.o
	@gcc -o I1 command.o game_loop.o game.o graphic_engine.o space.o game_reader.o player.o object.o libscreen.a 
	
command.o: command.c command.h
	@gcc -c -Wall command.c
	
player.o: player.c player.h types.h
	@gcc -c -Wall player.c

object.o: object.c object.h types.h 
	@gcc -c -Wall object.c
        
game_loop.o: game_loop.c graphic_engine.h game.h command.h
	@gcc -c -Wall game_loop.c
        
game.o: game.c game.h player.h object.h
	@gcc -c -Wall game.c
        
graphic_engine.o: graphic_engine.c libscreen.h graphic_engine.h command.h space.h types.h
	@gcc -c -Wall graphic_engine.c

space.o: space.c space.h object.h types.h 
	@gcc -c -Wall space.c

game_reader.o: game_reader.c game.h game_reader.h
	@gcc -c -Wall game_reader.c
	
programa: I1
	./I1 hormiguero.dat
	
clean: 
	rm  -f *.o 
