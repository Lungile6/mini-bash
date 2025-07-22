CC = gcc
CFLAGS = -Wall -Wextra

OBJ = main.o input.o parser.o executor.o

mini-shell: $(OBJ)
	$(CC) $(CFLAGS) -o mini-shell $(OBJ)

main.o: main.c input.h parser.h executor.h
input.o: input.c input.h
parser.o: parser.c parser.h
executor.o: executor.c executor.h

clean:
	rm -f *.o mini-shell