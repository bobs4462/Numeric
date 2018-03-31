CC := gcc
CCFLAGS := -g -std=c11 -O2
OBJ := greeting.o processf.o main.o farewell.o requestf.o gauss_it.o

all: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o gauss
	rm *.o

$(OBJ): helper.h

run:
	./gauss
