CC = gcc
CFLAGS = -Wall -std=c11 -g `pkg-config --cflags libxml-2.0` `pkg-config --cflags glib-2.0`
LIBS = `pkg-config --libs libxml-2.0` `pkg-config --libs glib-2.0`

INCLUDES = avl.o estrutura.o parser.o

includes: avl.o estrutura.o parser.o interface.o

avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c $(LIBS)

estrutura.o: estrutura.c estrutura.h avl.h
	$(CC) $(CFLAGS) -c estrutura.c $(LIBS)

parser.o: parser.c parser.h avl.h estrutura.h
	$(CC) $(CFLAGS) -c parser.c $(LIBS)

interface.o: interface.c interface.h avl.h estrutura.h parser.h
	$(CC) $(CFLAGS) -c interface.c $(LIBS)

clean: 
	rm *.o
