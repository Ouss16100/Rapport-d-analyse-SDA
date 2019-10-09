CC= gcc
CXXFLAGS= -Wall -ansi --pedantic -O3

#CPP_O_FILE = arraylist.o analyzer.o main.o
LIB = -lm


all: $(CPP_O_FILE)
	$(CC) $(CXXFLAGS) -o tas.exe main.o $(LIB)

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf tas.exe arraylist_analysis
