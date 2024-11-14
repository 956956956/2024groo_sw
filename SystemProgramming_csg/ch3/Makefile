CC=gcc
CFLAGS=-g -Wall
OBJS=main.o getstring.o prtstring.o 
TARGET=app.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.h main.c
	$(CC) $(CFLAGS) -c main.c

getstring.o: main.h getstring.c 
	$(CC) $(CFLAGS) -c getstring.c

prtstring.o: main.h prtstring.c
	$(CC) $(CFLAGS) -c prtstring.c 

clean:
	rm $(OBJS)
	rm $(TARGET)

