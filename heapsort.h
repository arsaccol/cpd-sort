#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <cstddef>

class Heap
{
public:
	// Assumes array is already allocated with size arraySize
	Heap(float* numArray, std::size_t arraySize);

	std::size_t parent(std::size_t childIndex) const
	{	return childIndex==0 ? 0 : (childIndex-1) / 2;	}

	std::size_t	leftChild(std::size_t parentIndex) const
	{	return parentIndex * 2 + 1;	}

	std::size_t rightChild(std::size_t parentIndex) const
	{	return parentIndex * 2 + 2;	}

private:
	float* _numArray;
	std::size_t _arraySize;
	std::size_t _heapSize;

};

#endif
