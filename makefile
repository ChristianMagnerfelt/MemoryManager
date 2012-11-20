all: memory_manager.o
	g++ -o MemoryManager memory_manager.o
memory_manager.o: memory_manager.cpp
	g++ -c -g -Wall memory_manager.cpp
clean:
	rm MemoryManager *.o
