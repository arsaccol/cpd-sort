#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "stddef.h"
#include <vector>

// Uses outside vector of n+1 elements, where
// n is the number of actual represented numbers
// such that vector[0] is not a number in the heap.
class MaxHeap
{
public:
	MaxHeap(std::vector<float>& numbers)
	:	mNumbers(numbers) 
	{
	}

	std::size_t leftChild(std::size_t index)
	{	return index << 1;	}

	std::size_t rightChild(std::size_t index)
	{	return (index << 1) + 1;	}

	std::size_t parent(std::size_t index)
	{	return index >> 1;	}


	void maxHeapify(std::size_t index);

	void buildMaxHeap();
	
	void printHeap(std::size_t initIndex = 0);
	

	
private:
	std::vector<float>& mNumbers;
	std::size_t heapSize;

};


#endif
