#pragma once
#pragma once
#include <vector>


namespace N2B_Sort
{
	template <class T>
	class Insertion_Sort
	{
	public:
		Insertion_Sort() {};

		void sort(T& numbers);
	};

	template <class T>
	void Insertion_Sort<T>::sort(T& numbers)
	{
		for (unsigned int i = 1; i < numbers.size(); i++)
		{
			T::value_type key = numbers[i];
			int j = i - 1;

			while (j >= 0 && numbers[j] > key)
			{
				numbers[j + 1] = numbers[j];
				j--;
			}
			numbers[j + 1] = key;
		}
	}


#ifdef TESTING
	static void insertion_sort_test()
	{
		using namespace N2B_Algo;
		std::cout << "insertion_sort_test():" << std::endl << std::endl;
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
		Insertion_Sort<std::vector<int>> sort;

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
		Insertion_Sort<std::vector<double>> sort_d;

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
