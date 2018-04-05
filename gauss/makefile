CC := gcc
CCFLAGS := -g -std=c11 -O2
OBJ := processf.o main.o requestf.o gcompute.o determ.o mx_check.o 

all: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o gauss
	./gauss
	rm *.o

$(OBJ): gauss.h

run:
	./gauss
