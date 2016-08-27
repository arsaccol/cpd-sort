#include <iostream>
#include <functional>
#include "numbers.h"
#include "insertion_sort.h"
#include "timer.h"

namespace tests
{
	// Test number generation capabilities
	// Saves a binary file with the generated vector.
	bool number_gen_test(int argc, char** argv)
	{
		if(argc != 2)
		{
			std::cout << "Incorrect usage." << std::endl;
			std::cout << "Specify a number of floats to generate for the test." << std::endl;
			return false;
		}

		std::size_t how_many = std::atoi(argv[1]);
	}

	// Returns the runtime of a sorting algorithm given a float vector and the algorithm function
	// Arguments: vector to be sorted, and void sort function with float vector as parameter
	double test_algorithm_time(std::vector<float>& number_vector, std::function<void(std::vector<float>&)> sort_fn)
	{
		Timer t; t.Start();

		sort_fn(number_vector);

		return t.GetMillisecondsElapsed();
	}

}

int main(int argc, char** argv)
{

	std::size_t how_many = 10;
	float seed = 1.f;

	//std::string filename = numbers::get_filename(how_many);

	std::vector<float> vec = numbers::generate_floats(how_many, seed);

	double elapsed = tests::test_algorithm_time(vec, sort::insertion_sort);

	numbers::print_numbers(vec);
	std::cout << "Sorting took " << elapsed << " milliseconds" << std::endl;

	if(numbers::is_sorted(vec))
	std::cout << "Number sequence is sorted" << std::endl;
	//numbers::save_numbers(vec, filename);
	return 0;
}
