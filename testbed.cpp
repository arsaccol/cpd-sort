#include <iostream>
#include <functional>
#include <cmath>
#include <map>
#include <fstream>
#include <algorithm>
#include "numbers.h"
#include "insertion_sort.h"
#include "timer.h"
#include "heapsort.h"

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

	void sorting_test_single_length(std::vector<std::map<std::size_t, double>>& maps, std::size_t how_many, float generation_seed = 0.f)
	{
		// Regular insertion sort
		std::vector<float> vec = numbers::generate_floats(how_many, generation_seed);
		std::cout << "Sorting an std::vector of " << how_many << " elements with regular insertion sort..." << std::endl;
		double elapsed = tests::test_algorithm_time(vec, sort::insertion_sort);
		if(numbers::is_sorted(vec))
		{
			std::cout << "Regular insertion sort successful!" << std::endl;
			std::cout << "Sorting with regular insertion sort took " << elapsed << " milliseconds" << std::endl;
		}
		maps[0][how_many] = elapsed;


		// Binary search insertion sort
		std::vector<float> vec_binary = numbers::generate_floats(how_many, generation_seed);
		std::cout << "Sorting an std::vector of " << how_many << " elements with binary search insertion sort..." << std::endl;
		double elapsed_binary = tests::test_algorithm_time(vec_binary, sort::insertion_sort_binary_search);
		if(numbers::is_sorted(vec_binary))
		{
			std::cout << "Binary search insertion sort successful!" << std::endl;
			std::cout << "Sorting with binary search insertion sort took " << elapsed_binary << " milliseconds" << std::endl;
		}
		maps[1][how_many] = elapsed_binary;

		// Quicksort
		std::vector<float> vec_quicksort = numbers::generate_floats(how_many, generation_seed);
		std::cout << "Sorting an std::vector of " << how_many << " elements with quicksort..." << std::endl;
		Timer quick_timer; quick_timer.Start();
		std::sort(std::begin(vec_quicksort), std::end(vec_quicksort), std::less_equal<float>());
		double elapsed_quicksort = quick_timer.GetMillisecondsElapsed();
		if(numbers::is_sorted(vec_quicksort))
		{
			std::cout << "Quicksort successful!" << std::endl;
			std::cout << "Sorting with quicksort took " << elapsed_quicksort << " milliseconds" << std::endl;
		}
		maps[2][how_many] = elapsed_quicksort;

		// Heapsort
		std::vector<float> vec_heapsort = numbers::generate_floats(how_many, generation_seed);
		std::cout << "Sorting an std::vector of " << how_many << " elements with heapsort..." << std::endl;
		double elapsed_heapsort = tests::test_algorithm_time(vec, sort::heap_sort);
		if(numbers::is_sorted(vec))
		{
			std::cout << "Heapsort successful!" << std::endl;
			std::cout << "Sorting with heapsort sort took " << elapsed << " milliseconds" << std::endl;
		}
		maps[3][how_many] = elapsed_heapsort;
	}

	void save_map(std::map<std::size_t, double>& the_map, std::string filename)
	{
		std::ofstream file;
		file.open(filename);

		for(auto &a : the_map)
		{
			file << a.first << " , " << a.second << std::endl;
		}

		file.close();
	}

}

int main(int argc, char** argv)
{
	std::vector<float> numbers = 
		numbers::generate_floats(50, 0);

	std::cout << "Before heap_sort()" << std::endl;
	for(std::size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	sort::heap_sort(numbers);
	
	std::cout << "After heap_sort()" << std::endl;
	for(std::size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";

	std::cout << std::endl;
	return 0;
}
