#include "insertion_sort.h"
#include <iostream>
#include <functional>
#include <cmath>

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

		auto bin_search = [number_vector, &current_key] (std::size_t begin, std::size_t end) -> std::size_t
		{
			std::size_t low = begin; std::size_t high = std::max(begin, end + 1);

			while(low < high)
			{
				std::size_t mid = std::floor((low + high) / 2);
				if(current_key <= number_vector[mid])
					high = mid;
				else
					low = mid + 1;
			}

			return high;
		};

		for(std::size_t unsorted_begin = 1; unsorted_begin < number_vector.size(); ++unsorted_begin)
		{
			current_key = number_vector[unsorted_begin];
			std::size_t insertion_pos = bin_search(0, unsorted_begin -1);
			std::cout << "Current insertion position of " << current_key << " is: " << insertion_pos << std::endl;

			auto shift_the_greater_ones = [&number_vector, &insertion_pos, &unsorted_begin] () -> void
			{
				for(std::size_t i = unsorted_begin; i > insertion_pos; --i)
				{
					number_vector[i] = number_vector[i - 1];

				}
			};

			shift_the_greater_ones();
			number_vector[insertion_pos] = current_key;
		}

	}
}
