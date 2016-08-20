#include <chrono>
#include <iostream>
#include <ctime>


int main()
{
	// For real time I guess...
    auto start = std::chrono::system_clock::now();

    for(auto i = 0; i < 9999999; ++i)
    {

    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);


    std::cout << "Elapsed time in milliseconds: " << elapsed.count() << std::endl;

	return 0;
}
