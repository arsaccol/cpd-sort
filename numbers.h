#ifndef NUMBERS_H
#define NUMBERS_H

#include <vector>
#include <string>

namespace numbers
{
	std::vector<float> generate_floats(std::size_t how_many, float seed);
	// Returns the index of the lookup value, or the index of where it should be
	std::size_t binary_search(std::vector<float>& vec, std::size_t begin, std::size_t end, float lookup);

	void save_numbers(const std::vector<float>& number_vector, const std::string& filename);
	void load_numbers(std::vector<float>& number_vector, const std::string& filename);

	std::string get_filename(std::size_t how_many);
	bool is_sorted(const std::vector<float>& number_vector);
	void print_numbers(const std::vector<float>& number_vector);
}

#endif // NUMBERS_H

