all : snake_jeu

snake.o: snake.c snake.h
	gcc -Wall -c snake.c 
   
snake_jeu.o: snake_jeu.c snake.h
	gcc -Wall -c snake_jeu.c
 
snake_jeu: snake_jeu.o snake.o 
	gcc -o snake_jeu snake_jeu.o snake.o -lncurses
 	
clean: 
	rm -f snake_jeu *.o *~