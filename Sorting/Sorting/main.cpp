#include <iostream>


#include "../../Unsorted List Generator/Unsorted List Generator/Sequence_Generator.h"


#define TESTING
#include "Insertion_Sort.h"
#include "Merge_Sort.h"
#include "Heap_Sort.h"
#include "Quick_Sort.h"
#include "Counting_Sort.h"

int main()
{
	using namespace N2B_Algo;
	using namespace N2B_Sort;

	merge_sort_test();
	std::cout << "--------------------------------------------------"
		<< std::endl << std::endl;
	insertion_sort_test();
	std::cout << "--------------------------------------------------"
		<< std::endl << std::endl;
	heap_sort_test();
	std::cout << "--------------------------------------------------"
		<< std::endl << std::endl;
	quick_sort_test();
	std::cout << "--------------------------------------------------"
		<< std::endl << std::endl;
	counting_sort_test();

	char ch;
	std::cin >> ch;
}
