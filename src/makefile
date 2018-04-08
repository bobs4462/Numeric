CC := gcc
CCFLAGS := -g -std=c11 -O2 -lm
OBJ := processf.o main.o requestf.o gcompute.o determ.o icompute.o zcompute.o restructure.o show_state.o menu.o printslow.o 

all: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o numeric
	rm *.o

$(OBJ): library.h

run:
	./numeric

clean:
	rm *.o numeric
