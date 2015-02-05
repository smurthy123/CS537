
all: multable

multable: mult_object.o
	gcc mult_object.o -o multable

mult_object.o: multable.c
	gcc -c -Wall multable.c -o mult_object.o

clean:
	rm mult_object.o multable
	
