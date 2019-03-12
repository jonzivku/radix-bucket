# Makefile for p4, an implementation of Radix/Bucket Sort hybrid

# defining target dependencies and files
p3: main.o
	g++ -o p4 main.o -Wall

# defining how each object file is to be built
main.o: main.cpp
	g++ -c main.cpp -Wall

# clean up
clean:
	rm -f p4 *.o *~
