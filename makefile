OBJS	= searchmain.o readDir.o
SOURCE	= searchmain.c readDir.c
HEADER	= header.h
OUT	= a.out
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

a.out: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
searchmain.o: searchmain.c
	$(CC) $(FLAGS) searchmain.c -lcunit

readDir.o: readDir.c
	$(CC) $(FLAGS) readDir.c -lcunit


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)