/*
 *	\brief	This file contains tests of a memory manager for new and delete operators
 *	\author	Christian Magnerfelt
 *	\date	2012.11.20
 */
#include "memory_manager.h"
#include "complex.h"

#include <cstddef>

MemoryManager memoryManager;	//!< Global memory manager


/*
 *	\brief	operator new wrapper
 */
//void * operator new (std::size_t size)
//{
//	return ::memoryManager.allocate(size);
//}
/*
 *	\brief	operator new [] wrapper
 */
//void * operator new[] (std::size_t size)
//{
//	return ::memoryManager.allocate(size);
//}
/*
 *	\brief	operator delete wrapper
 */
//void operator delete (void * pointerToDelete)
//{
//	::memoryManager.free(pointerToDelete);
//}
/*
 *	\brief	operator delete [] wrapper
 */
//void operator delete[] (void * arrayToDelete)
//{
//	::memoryManager.free(arrayToDelete);
//}

int main()
{
	Complex * arr[1000];
	for(int i = 0; i < 5000; ++i)
	{
		for(int j = 0; j < 1000; ++j)
		{
			arr[j] = new Complex(i, j);
		}
		for(int j = 0; j < 1000; ++j)
		{
			delete arr[j];
		}
	}
	return 0;
}
