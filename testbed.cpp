#include <iostream>
#include <functional>
#include <cmath>
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

	void run_single_length_tests(std::size_t how_many, float generation_seed = 0.f)
	{
		std::vector<float> vec = numbers::generate_floats(how_many, generation_seed);
		std::vector<float> vec_binary = numbers::generate_floats(how_many, generation_seed);

		// Regular insertion sort
		std::cout << "Sorting an std::vector of " << how_many << " elements with regular insertion sort..." << std::endl;
		double elapsed = tests::test_algorithm_time(vec, sort::insertion_sort);
		if(numbers::is_sorted(vec))
		{
			std::cout << "Regular insertion sort successful!" << std::endl;
			std::cout << "Sorting took with regular insertion sort took " << elapsed << " milliseconds" << std::endl;
		}


		// Binary search insertion sort
		std::cout << "Sorting an std::vector of " << how_many << " elements with binary search insertion sort..." << std::endl;
		double elapsed_binary = tests::test_algorithm_time(vec_binary, sort::insertion_sort_binary_search);
		if(numbers::is_sorted(vec_binary))
		{
			std::cout << "Binary search insertion sort successful!" << std::endl;
			std::cout << "Sorting took with binary search insertion sort took " << elapsed_binary << " milliseconds" << std::endl;
		}



	}

}

int main(int argc, char** argv)
{
	std::size_t how_many = 10000;

	//std::string filename = numbers::get_filename(how_many);
	//std::vector<float> vec= {1.f, 2.f, 4.f, 8.f, 16.f, 32.f, 64.f, 128.f};
	//std::vector<float> vec = {128.f, 64.f, 32.f, 16.f, 8.f, 4.f, 2.f, 1.f};


	tests::run_single_length_tests(how_many);



	//numbers::save_numbers(vec, filename);
	return 0;
}
