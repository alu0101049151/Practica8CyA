
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transition.o State.o Alphabet.o 

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o G2NFA ${OBJS}

clean:
	rm -rf *.o *.txt *.gv G2NFA
