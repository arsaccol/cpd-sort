#include "numbers.h"
#include <iostream>
int main()
{
	std::size_t how_many = 25;
	std::string filename = numbers::get_filename(how_many);



	std::vector<float> vec = numbers::generate_floats(how_many);
	numbers::save_numbers(vec, filename);
	return 0;
}
