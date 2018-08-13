CC = gcc

OBJ = main.o
LIB = 
INCLUDE = 
CFLAGS = -Werror -g

target = test

all: $(OBJ) 
	$(CC) $^ -o $(target) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf *.o $(target)
