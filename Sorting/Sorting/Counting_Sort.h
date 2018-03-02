#pragma once
#include <vector>


namespace N2B_Sort
{
	template <class T>
	class Counting_Sort
	{
	public:
		Counting_Sort() {}

		void sort(T& numbers, int max)
		{
			std::vector<int> counts(max + 1, 0);
			std::vector<int> unsorted(numbers);

			for (int i = 0; i < unsorted.size(); i++)
				counts[unsorted[i]]++;

			for (int i = 1; i < counts.size(); i++)
				counts[i] = counts[i - 1] + counts[i];

			for (int i = unsorted.size() - 1; i >= 0; i--)
				numbers[counts[unsorted[i]]-- - 1] = unsorted[i];
		}
	};

	static void counting_sort_test() 
	{
		using namespace N2B_Algo;
		std::cout << "counting_sort_test():" << std::endl << std::endl;
		int max = 5;

		//RAND
		std::cout << "Unsorted Int:" << std::endl;
		Random_Int_Sequence_Generator<std::vector<int>> random(5, 0, max);

		std::cout << "Random_Int_Sequence_Generator:" << std::endl;
		for (auto i : random.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		std::cout << "Unsorted_Sequence_Generator:" << std::endl;
		Unsorted_Sequence_Generator<std::vector<int>> unsorted(max, 0);
		for (auto i : unsorted.numbers())
			std::cout << i << " ";
		std::cout << std::endl << std::endl;

		//SORT
		std::cout << "Sorted Int:" << std::endl;
		Counting_Sort<std::vector<int>> sort;

		std::cout << "Sorted Random_Int_Sequence_Generator:" << std::endl;

		sort.sort(random.numbers(), max);
		for (auto i : random.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		std::cout << "Sorted Unsorted_Sequence_Generator:" << std::endl;
		sort.sort(unsorted.numbers(), max);
		for (auto i : unsorted.numbers())
			std::cout << i << " ";
		std::cout << std::endl << std::endl;
	}
}