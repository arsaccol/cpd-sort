#include "heapsort.h"
#include <algorithm>
#include <iostream>

Heap::Heap(float* numArray, std::size_t arraySize)
	:	_numArray(numArray), _arraySize(arraySize), _heapSize(arraySize)
{
	buildHeap();
}

void Heap::buildHeap()
{
	std::cout << "Executing buildHeap()" << std::endl;
	_heapSize = _arraySize;
	for(std::size_t i = _arraySize / 2; i > 0; --i)
		heapify(i);
}

void Heap::heapify(std::size_t index)
{
	std::cout << "Heapifying at index " << index << std::endl;
	printArray();
	std::size_t left = leftChild(index);
	std::size_t right = rightChild(index);
	std::size_t largest;

	if(left <= _heapSize && _numArray[left] > _numArray[index])
		largest = left;
	else
		largest = index;

	if(right <= _heapSize && _numArray[right] > _numArray[index])
		largest = right;

	if(largest != index)
	{
		// Exchange largest and currently indexed 
		float temp = _numArray[index];
		_numArray[index] = _numArray[largest];
		_numArray[largest] = temp;

		heapify(largest);
	}
}

void Heap::printArray()
{
	std::cout << "Array is currently: ";
	for(std::size_t i = 0; i < _arraySize; ++i)
		std::cout << _numArray[i] << " ";

	std::cout << std::endl;
}
