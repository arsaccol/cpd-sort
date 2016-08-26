#include "insertion_sort.h"

namespace sort
{
	// The n-sized vector is logically divided into two, S1 and S2.
	// S1 is the sorted section, S2 is the unsorted section.
	// S1 starts out with one element; S2 starts with n-1 elements.
	// A loop begins. At each iteration of the loop, the leftmost
	// element of S2, x, is inserted into S1 such that any elements of S1
	// to its left are less than x, and any elements to the right of x are
	// less than x.
	void insertion_sort(std::vector<float>& numbers)
	{
		float current_key;

		for(std::size_t j = 1; j < numbers.size(); ++j)
		{
			current_key = numbers[j];
			std::size_t i = j - 1;

			while(i > 0 && numbers[i] > current_key)
			{
				numbers[i+1] = numbers[i];
				--i;
			}

			numbers[i + 1] = current_key;
		}
	}
}
