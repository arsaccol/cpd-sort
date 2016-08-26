#include "insertion_sort.h"

namespace sort
{
	void insertion_sort(std::vector<float>& numbers)
	{
		float current_key;

		for(std::size_t sorted_end = 1; sorted_end < numbers.size(); ++sorted_end)
		{
			current_key = numbers[sorted_end];
			std::size_t insertion_pos = sorted_end - 1;

			// Look for best position for insertion
			while(insertion_pos > 0 && numbers[insertion_pos] > current_key)
			{
				numbers[insertion_pos+1] = numbers[insertion_pos];
				--insertion_pos;
			}

			numbers[insertion_pos + 1] = current_key;
		}
	}
}
