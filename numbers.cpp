#include <iostream>
#include <random>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
namespace numbers
{
	float seed = 1.f;

	std::vector<float> generate_floats(std::size_t how_many)
    {
        std::mt19937 number_gen;
        number_gen.seed(seed);
		std::uniform_real_distribution<float> distribution(0, how_many);

		std::vector<float> numbers;

        for(unsigned i = 0; i < how_many; ++i)
        {
			numbers.push_back(distribution(number_gen));

        }

        return numbers;
    }

	void save_numbers(const std::vector<float>& number_vector, const std::string& filename)
	{
		std::ofstream file;
		file.open(filename, std::ios::out | std::ios::binary);

		std::size_t vector_size = number_vector.size();


		// Store the vector size on start of file
		file.write((char*)&vector_size, sizeof(vector_size));
		// Store the actual numbers data
		file.write((char*)&number_vector[0], number_vector.size() * sizeof(float));

		file.close();
	}

	void load_numbers(std::vector<uint32_t>& number_vector, const std::string& filename)
	{
		std::ifstream file;
		std::size_t vector_size;

		file.open(filename, std::ios::in | std::ios::binary);

		file.read((char*)&vector_size, sizeof(std::size_t));
		number_vector.reserve(vector_size * sizeof(float));

		file.read(reinterpret_cast<char*>(number_vector.data()), sizeof(float) * vector_size);
	}

	// Create a filename with a .nr extension, based
	// on the number provided
	// e.g., if how_many == 25, return "25.nr"
	std::string get_filename(std::size_t how_many)
	{
		std::string name = std::to_string(how_many) + ".nr";

		return name;
	}

}
int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "You need to specify how many numbers you want to generate." << std::endl;
		std::cout << "Try again." << std::endl << std::endl;
		return -1;
	}

	std::size_t how_many = std::atoi(argv[1]);

	std::string dir_name = "data-sets/";
	system(("rm -rf " + dir_name).c_str());
	system(("mkdir " + dir_name).c_str());


	std::vector<float> mynumbers = numbers::generate_floats(how_many);
	numbers::save_numbers(mynumbers, dir_name + numbers::get_filename(how_many));

	for(auto i : mynumbers)
		std::cout << i << " ";
	std::cout << std::endl;



	return 0;
}
