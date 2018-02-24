#pragma once
#include <vector>
#include <iostream>

namespace N2B_Sort
{
	template <class T>
	class Merge_Sort
	{
	public:
		Merge_Sort() {};

		void sort(T& numbers);
		void merge_sort(T& numbers, int l, int r);
		void merge(T& numbers, int l, int m, int r);

	};

	template <class T>
	void Merge_Sort<T>::sort(T& numbers)
	{
		merge_sort(numbers, 0, numbers.size() - 1);
	}

	template <class T>
	void Merge_Sort<T>::merge_sort(T& numbers, int l, int r)
	{
		if (l < r)
		{
			int m = (l + r) / 2;
			merge_sort(numbers, l, m);
			merge_sort(numbers, m + 1, r);

			merge(numbers, l, m, r);
		}
	}

	template <class T>
	void Merge_Sort<T>::merge(T& numbers, int l, int m, int r)
	{
		T left(numbers.begin() + l, numbers.begin() + m + 1);
		T right(numbers.begin() + m + 1, numbers.begin() + r + 1);

		auto l_i = left.begin(), r_i = right.begin();
		int  i = l;
		//compare and fill main container
		while (l_i != left.end() && r_i != right.end())
			if (*l_i < *r_i)
				numbers[i++] = *(l_i++);
			else
				numbers[i++] = *(r_i++);
		//fill container with all left numbers
		while (l_i != left.end())
			numbers[i++] = *(l_i++);
		while (r_i != right.end())
			numbers[i++] = *(r_i++);
	}

#ifdef TESTING
	static void merge_sort_test()
	{
		using namespace N2B_Algo;
		std::cout << "merge_sort_test():" << std::endl << std::endl;
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
		Merge_Sort<std::vector<int>> sort;

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
		Merge_Sort<std::vector<double>> sort_d;

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
#endif
}
