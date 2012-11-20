#ifndef COMPLEX_H
#define COMPLEX_H
/*
 *	\brief		A simple class that stores complex numbers
 *	\details	The class uses a cusom memory manager for new and delete operations
 */
 
#include <cstddef>
 
class Complex
{
	public:
		Complex (double r, double c): m_r(r), m_c(c) {}
		void * operator new(std::size_t size);
		void operator delete(void * pointerToDelete);
	private:
		double m_r; // Real part
		double m_c; // Complex part
};
#endif
