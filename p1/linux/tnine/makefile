compiler = gcc

flags = -c -Wall -Werror


all: tnine

tnine: tnine_object.o printwrapper.o
	$(compiler) tnine_object.o printwrapper.o -o tnine

tnine_object.o: main_handout.c
	$(compiler) $(flags) main_handout.c -o tnine_object.o

clean:
	rm tnine_object.o tnine
