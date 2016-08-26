#include <iostream>
#include "numbers.h"
#include "insertion_sort.h"

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

}

int main(int argc, char** argv)
{

	std::size_t how_many = 25;
	std::string filename = numbers::get_filename(how_many);

	std::cout << "Attempting to create sorted vector..." << std::endl;
	std::vector<float> vec = numbers::generate_floats(how_many);
	std::cout << "Finished creating vector."<< std::endl;

	sort::insertion_sort(vec);

	numbers::print_numbers(vec);
	if(numbers::is_sorted(vec))
		std::cout << "Number sequence is sorted" << std::endl;
	//numbers::save_numbers(vec, filename);
	return 0;
}
