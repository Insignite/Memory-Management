#include "MemoryManager.h"
#include <cstdlib>
#include<iostream>
#include<iomanip>
//#include "stdafx.h"

using namespace std;

namespace MemoryManager
{
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
	//
	// This is the only static memory that you may use, no other global variables
	// may be created, if you need to save data make it fit in MM_pool
	//
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];
	// I have provided this tool for your use
	void memView(int start, int end)
	{
		const unsigned int SHIFT = 8;
		const unsigned int MASK = 1 << SHIFT - 1;
		unsigned int value;	// used to facilitate bit shifting and masking
		cout << " Pool Unsignd Unsigned " << endl;
		cout << "Mem Add indx bits chr ASCII# short int " << endl;
		cout << "-------- ---- -------- --- ------ ------- ------------" << endl;
		for (int i = start; i <= end; i++)
		{
			cout << (long*)(MM_pool + i) << ':';	// the actual address in hexadecimal
			cout << '[' << setw(2) << i << ']';	// the index into MM_pool
			value = MM_pool[i];
			cout << " ";
			for (int j = 1; j <= SHIFT; j++)	// the bit sequence for this byte (8 bits)
			{
				cout << ((value & MASK) ? '1' : '0');
				value <<= 1;
			}
			cout << " ";
			cout << '|' << *(char*)(MM_pool + i) << "| (";	// the ASCII character of the 8 bits (1 byte)
			cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")";// the ASCII number of the character
			cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")";// the unsigned short value of 16 bits (2 bytes)
			cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")";	// the unsigned int value of 32 bits (4 bytes)
			cout << endl;
		}
	}
	// Initialize set up any data needed to manage the memory pool

	void initializeMemoryManager(void)
	{
		*((unsigned short*)MM_pool) = 6; // First Memory
		*((unsigned short*)MM_pool + 2) = 0;
		*((unsigned short*)MM_pool + 4) = 0;
	}

	// Return a pointer inside the memory pool
	void* allocate(int aSize)
	{

		unsigned short NAM = *((unsigned short*)MM_pool); // Next Available memory
		unsigned short* current = (unsigned short*)(MM_pool + NAM); // Finds the current memory that that is available after NAM


		*current = aSize; // current is the size of memory
		*(current + 1) = *(unsigned short*)(MM_pool + 2); // Next
		*(current + 2) = 0; // Previous

		unsigned short currentNextindex = *(unsigned short *)(MM_pool + 2);
		unsigned short* currentNext = (unsigned short*)(MM_pool + currentNextindex);

		if (currentNextindex != 0)
		{
			*(currentNext + 2) = NAM; 
		}
		else
		{
			*(currentNext + 2) = 0; 
		}

		*((unsigned short*)(MM_pool + 2)) = NAM;
		*((unsigned short*)MM_pool) += aSize + 6;
		return (void*)&MM_pool[NAM + 6];
	}

	// Scan the memory pool and return the total free space remaining in bytes
	int freeMemory(void)
	{
		return MM_POOL_SIZE - usedMemory() - inUseMemory() - 6; // Returns free memory
	}


	// Scan the memory pool and return the total deallocated memory in bytes
	void deallocate(void* aPointer)
	{

		int previous = *(unsigned short*)((char*)aPointer - 2);
		int next = *(unsigned short*)((char*)aPointer - 4);
		int currentNext = (*(unsigned short*)(MM_pool + previous + 2));

		*(unsigned short*)(MM_pool + previous + 2) = *(unsigned short*)(MM_pool + currentNext + 2);

		if (next != 0) {
			*(unsigned short*)(MM_pool + next + 4) = *(unsigned short*)(MM_pool + currentNext + 4);
		}

		(*(unsigned short*)(MM_pool + currentNext + 2)) = (*(unsigned short*)(MM_pool + 4));
		(*(unsigned short*)(MM_pool + currentNext + 4)) = 0;
		(*(unsigned short*)(MM_pool + ((*(unsigned short*)(MM_pool + 4))) + 4)) = currentNext;
		(*(unsigned short*)(MM_pool + 4)) = currentNext;
	}

	int usedMemory(void)
	{
		int num = 0;
		int next = 0;
		int currentNext = *(unsigned short*)((char*)MM_pool + 4);
		if (currentNext != 0)
		{
			next = *(unsigned short*)((char*)(MM_pool + 4));
		}
		else {

		}
		while (next != 0) // Runs until next  is not 0
		{
			currentNext = next;
			next = *(unsigned short*)((char*)MM_pool + currentNext + 2);
			num += *(unsigned short*)((char*)MM_pool + currentNext) + 6;
		}
		return  num;
	}


	// Scan the memory pool and return the total in use memory
	int inUseMemory(void)
	{
		return *(unsigned short*)MM_pool - 6 - usedMemory();
	}

	// Return the size (in bytes) associated with this memory address
	int size(void * aPointer)
	{
		return *(unsigned short*)((char*)aPointer - 6);
	}

	// This is called when no more memory is available to allocate
	void onOutOfMemory(void)
	{
		std::cerr << "/nMemory pool out of memory" << std::endl;
		cin.get();
		exit(1);
	}


}
