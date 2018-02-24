#pragma once
#include <vector>


#include "../../Data structures/Data structures/Heap.h"

namespace N2B_Sort
{
	template <class T>
	class Heap_Sort
	{
	public:
		Heap_Sort(){}

		void sort(T& numbers)
		{
			N2B_Algo::Max_Heap<T> heap(numbers);

			for (int i = numbers.size() - 1; i >= 0; i--)
			{
				numbers[i] = heap.extract_max();
			}
		}
	};

#ifdef TESTING
	void heap_sort_test()
	{
		using namespace N2B_Algo;
		std::cout << "heap_sort_test():" << std::endl << std::endl;
		//RAND
		std::cout << "Unsorted Int:" << std::endl;
		Random_Int_Sequence_Generator<std::vector<int>> random(10, -5, 5);

		std::cout << "Random_Int_Sequence_Generator:" << std::endl;
		for (auto i : random.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "Unsorted_Sequence_Generator:" << std::endl;
		Unsorted_Sequence_Generator<std::vector<int>> unsorted(10, -5);
		for (auto i : unsorted.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl << std::endl;

		//SORT
		std::cout << "Sorted Int:" << std::endl;
		Heap_Sort<std::vector<int>> sort;

		std::cout << "Sorted Random_Int_Sequence_Generator:" << std::endl;

		sort.sort(random.numbers());
		for (auto i : random.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "Sorted Unsorted_Sequence_Generator:" << std::endl;
		sort.sort(unsorted.numbers());
		for (auto i : unsorted.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl << std::endl;



		//RAND
		std::cout << "Unsorted Real:" << std::endl;
		Random_Real_Sequence_Generator<std::vector<double>> random_d(10, -5, 5);

		std::cout << "Random_Real_Sequence_Generator:" << std::endl;
		for (auto i : random_d.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "Unsorted_Sequence_Generator:" << std::endl;
		Unsorted_Sequence_Generator<std::vector<double>> unsorted_d(10, -5, 2.2);
		for (auto i : unsorted_d.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl << std::endl;

		//SORT
		std::cout << "Sorted Real:" << std::endl;
		Heap_Sort<std::vector<double>> sort_d;

		std::cout << "Sorted Random_Real_Sequence_Generator:" << std::endl;

		sort_d.sort(random_d.numbers());
		for (auto i : random_d.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "Sorted Unsorted_Sequence_Generator:" << std::endl;
		sort_d.sort(unsorted_d.numbers());
		for (auto i : unsorted_d.numbers())
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
}
#endif // TESTING

}
