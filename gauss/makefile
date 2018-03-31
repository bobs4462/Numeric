CC := gcc
CCFLAGS := -g -std=c11 -O2
OBJ := processf.o main.o requestf.o gcompute.o

all: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o gauss
	rm *.o

$(OBJ): gauss.h

run:
	./gauss
