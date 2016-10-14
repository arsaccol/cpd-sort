#include "heapsort.h"
#include <algorithm>
#include <iostream>
void MaxHeap::maxHeapify(std::size_t index)
{
	std::cout << "Heapifying at " << index << std::endl;
	std::cout << "Array: ";
	for(std::size_t i = 0; i < mNumbers.size(); ++i)
		std::cout << mNumbers[i] << " ";
	std::cout << std::endl;

	std::size_t left = leftChild(index);
	std::size_t right = rightChild(index);
	std::size_t largest = index;

	if(left <= heapSize && mNumbers[left] > mNumbers[index])
		largest = left;
	else
		largest = index;
	
	if(right <= heapSize && mNumbers[right] > mNumbers[largest])
			largest = right;

	std::cout << "Largest is at " << largest << std::endl;
	std::cout << "Current is " << index << std::endl;

	if(largest != index)
	{
		std::swap(mNumbers[index], mNumbers[largest]);
		maxHeapify(largest);
	}
}

void MaxHeap::buildMaxHeap()
{
	heapSize = mNumbers.size() - 1;

	for(std::size_t i = (heapSize >> 1); i != 0; --i)
	{
		std::cout << "heapSize: " << heapSize << std::endl;
		maxHeapify(i);
	}
}


void printHeap(std::size_t initIndex = 0)
{

}
