#ifndef NUMBERS_H
#define NUMBERS_H

namespace numbers
{
	std::vector<float> generate_floats(std::size_t how_many);
	void save_numbers(const std::vector<float>& number_vector, std::string& filename);
	void load_numbers(std::vector<uint32_t>& number_vector, const std::string& filename);
	std::string get_filename(std::size how_many);
}

#endif // NUMBERS_H

