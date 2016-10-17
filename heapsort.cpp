#include "heapsort.h"
#include <algorithm>
#include <iostream>
namespace sort
{
	void heap_sort(std::vector<float>& numbers)
	{
		MaxHeap h(numbers);
		h.heapSort();
	}

	void MaxHeap::maxHeapify(std::size_t index)
	{
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

	void MaxHeap::heapSort()
	{
		for(std::size_t i = heapSize; i >= 2; --i)
		{
			std::swap(mNumbers[1], mNumbers[i]);
			--heapSize;
			maxHeapify(1);
		}
	}
}
