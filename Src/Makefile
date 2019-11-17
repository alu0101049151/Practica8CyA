
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transition.o State.o Alphabet.o Production.o Nfa.o Grammar.o mainG2NFA.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o G2NFA ${OBJS}

clean:
	rm -rf *.o *.txt *.gv *.nfa *.gra G2NFA
