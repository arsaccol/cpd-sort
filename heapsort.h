#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "stddef.h"
#include <vector>

// Uses outside vector of n+1 elements, where
// n is the number of actual represented numbers
// such that vector[0] is not a number in the heap.

namespace sort
{
	void heap_sort(std::vector<float>& numbers);

	class MaxHeap
	{
	public:
		MaxHeap(std::vector<float>& numbers)
		:	mNumbers(numbers) 
		{
			buildMaxHeap();
		}

		std::size_t leftChild(std::size_t index) const
		{	return index << 1;	}

		std::size_t rightChild(std::size_t index) const
		{	return (index << 1) + 1;	}

		std::size_t parent(std::size_t index) const
		{	return index >> 1;	}

		std::size_t getHeapSize()	const
		{	return heapSize;	}


		void heapSort();

		void maxHeapify(std::size_t index);

		void buildMaxHeap();
		
			
	private:
		std::vector<float>& mNumbers;
		std::size_t heapSize;

	};

}

#endif
