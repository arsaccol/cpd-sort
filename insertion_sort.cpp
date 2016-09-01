#include "insertion_sort.h"
#include "numbers.h"
#include <iostream>

namespace sort
{
	void insertion_sort(std::vector<float>& number_vector)
	{
		float current_key;

		for(std::size_t unsorted_begin = 1; unsorted_begin < number_vector.size(); ++unsorted_begin)
		{
			current_key = number_vector[unsorted_begin];

			// Index of where insertion position will be placed
			std::size_t insertion_pos = unsorted_begin - 1;

			// Look for best position for insertion
			while(insertion_pos >= 0 && number_vector[insertion_pos] > current_key)
			{
				// and shift every element greater than current_key to the right
				number_vector[insertion_pos+1] = number_vector[insertion_pos];
				--insertion_pos;
			}

			number_vector[insertion_pos + 1] = current_key;
		}
	}

	void insertion_sort_binary_search(std::vector<float>& number_vector)
	{
		float current_key;

		for(std::size_t unsorted_begin = 1; unsorted_begin < number_vector.size(); ++unsorted_begin)
		{
			current_key = number_vector[unsorted_begin];

			// Do a binary search for the position to insert the current key in
			auto insert_pos = numbers::binary_search(number_vector, 0, unsorted_begin - 1, current_key);
			// Element-by-element shift to the right, to make room
			for(std::size_t current_shift = unsorted_begin; current_shift > insert_pos; --current_shift)
			{
				number_vector[current_shift] = number_vector[current_shift - 1];
			}
			// "Current" element is finally inserted
			number_vector[insert_pos] = current_key;
		}

	}
}
