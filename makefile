all: memory_manager.o main.o complex.o
	g++ -o MemoryManager memory_manager.o main.o complex.o
main.o: main.cpp
	g++ -c -g -Wall main.cpp	
memory_manager.o: memory_manager.cpp 
	g++ -c -g -Wall memory_manager.cpp
complex.o: complex.cpp
	g++ -c -g -Wall complex.cpp
clean:
	rm MemoryManager *.o
