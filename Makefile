All: I1 clean programa
I1: command.o game_loop.o game.o graphic_engine.o space.o
	@gcc -o I1 command.o game_loop.o game.o graphic_engine.o space.o libscreen.a
	
command.o: command.c command.h
	@gcc -c -Wall command.c
        
game_loop.o: game_loop.c graphic_engine.h game.h command.h
	@gcc -c -Wall game_loop.c
        
game.o: game.c game.h
	@gcc -c -Wall game.c
        
graphic_engine.o: graphic_engine.c libscreen.h graphic_engine.h command.h space.h types.h
	@gcc -c -Wall graphic_engine.c

space.o: space.c space.h
	@gcc -c -Wall space.c
	
programa: I1
	./I1 hormiguero.dat
	
clean: 
	rm  -f *.o 
