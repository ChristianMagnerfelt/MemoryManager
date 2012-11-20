#include <cstddef>

/*
 *	\brief	Memory manager interface
 */
class IMemoryManager
{
	public:
		virtual ~IMemoryManager() {}
		virtual void * allocate(std::size_t) = 0;
		virtual void free(void *) = 0;
};
/*
 *	\brief	Memory manager
 */
class MemoryManager : public IMemoryManager
{
	public:
		MemoryManager();
		~MemoryManager();
		void * allocate(std::size_t size);
		void free(void * pointerToFree); 
};

MemoryManager memoryManager;	//!< Global memory manager

/*
 *	\brief	operator new wrapper
 */
void * operator new (std::size_t size)
{
	return ::memoryManager.allocate(size);
}
/*
 *	\brief	operator new [] wrapper
 */
void * operator new[] (std::size_t size)
{
	return ::memoryManager.allocate(size);
}
/*
 *	\brief	operator delete wrapper
 */
void operator delete (void * pointerToDelete)
{
	::memoryManager.free(pointerToDelete);
}
/*
 *	\brief	operator delete [] wrapper
 */
void operator delete[] (void * arrayToDelete)
{
	::memoryManager.free(arrayToDelete);
}

class Complex
{
	public:
		Complex (double r, double c): m_r(r), m_c(c) {}
	private:
		double m_r; // Real part
		double m_c; // Complex part
};

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
