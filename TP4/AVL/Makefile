CC= gcc
CXXFLAGS= -Wall -ansi --pedantic -O3

CPP_O_FILE = avl_tree.o analyzer.o main.o
LIB = -lm


all: $(CPP_O_FILE)
	$(CC) $(CXXFLAGS) -o avl_analysis $(CPP_O_FILE) $(LIB)

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf avl_analysis
