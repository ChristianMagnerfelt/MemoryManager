#include "complex.h"
#include "memory_manager.h"

#include <cstddef>

extern MemoryManager memoryManager;

void * Complex::operator new(std::size_t size)
{
	return ::memoryManager.allocate(size);
}
void Complex::operator delete (void * pointerToDelete)
{
	::memoryManager.free(pointerToDelete);
}
