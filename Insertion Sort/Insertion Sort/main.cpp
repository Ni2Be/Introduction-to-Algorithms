#include <iostream>

#include "../../Unsorted List Generator/include/Sequence_Generator.h"


int main()
{
	using namespace N2B_Algo;
	Random_Int_Sequence_Generator<std::vector<int>> random(10, -5, 5);


	std::cout << "Random_Real_Sequence_Generator:" << std::endl;
	for (auto i : random.numbers)
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Unsorted_Sequence_Generator:" << std::endl;
	Unsorted_Sequence_Generator<std::vector<double>> unsorted(10, -5, 0.2);
	for (auto i : unsorted.numbers)
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;


	char ch;
	std::cin >> ch;
}