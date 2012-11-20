#include "memory_manager.h"
#include "complex.h"

void * MemoryManager::allocate(std::size_t size)
{
	if(freeStoreHead == 0)
		expandPoolSize();
	FreeStore * head = freeStoreHead;
	freeStoreHead = head->next;
	return head;
}
void MemoryManager::free(void * deleted)
{
	FreeStore * head = static_cast<FreeStore*>(deleted);
	head->next = freeStoreHead;
	freeStoreHead = head;
}

#define POOLSIZE 32

void MemoryManager::expandPoolSize()
{
	std::size_t size = (sizeof(Complex) > sizeof(FreeStore*)) ? sizeof(Complex) : sizeof(FreeStore*);
	FreeStore * head = reinterpret_cast<FreeStore*> (new char[size]);
	freeStoreHead = head;
	
	for(int i = 0; i < POOLSIZE; ++i)
	{
		head->next = reinterpret_cast <FreeStore*> (new char[size]);
		head = head->next;
	}
	head->next = 0;
}

void MemoryManager::cleanUp()
{
	FreeStore * nextPtr = freeStoreHead;
	for(; nextPtr != 0; nextPtr = freeStoreHead)
	{
		freeStoreHead = freeStoreHead->next;
		delete [] nextPtr;
	}
}

