#pragma once
#include <vector>
#include <random>

namespace N2B_Sort
{
	template <class T>
	class Quick_Sort
	{
	public:
		Quick_Sort(){}

		void sort(T& numbers);
	private:
		std::random_device			  m_rd;

		void quick_sort(T& numbers, int l, int h);
		int  randomized_partition(T& numbers, int l, int h);
		void exchange(T& numbers, int first, int second);
	};

	template <class T>
	void Quick_Sort<T>::sort(T& numbers)
	{
		quick_sort(numbers, 0, numbers.size() - 1);
	}

	template <class T>
	void Quick_Sort<T>::quick_sort(T& numbers, int l, int h)
	{
		if (l < h)
		{
			int inplace_index = randomized_partition(numbers, l, h);
			quick_sort(numbers, l, inplace_index - 1);
			quick_sort(numbers, inplace_index + 1, h);
		}
	}

	template <class T>
	int Quick_Sort<T>::randomized_partition(T& numbers, int l, int h)
	{
		//randomize pivot
		std::uniform_int_distribution<int> int_dist(l, h - 1);
		exchange(numbers, int_dist(m_rd), h);

		T::value_type pivot         = numbers[h];
		int           smaller_index = l;

		for (int i = l; i <= h - 1; i++)
		{
			if (numbers[i] <= pivot)
				exchange(numbers, smaller_index++, i);
		}

		exchange(numbers, smaller_index, h);

		return smaller_index;
	}

	template <class T>
	void Quick_Sort<T>::exchange(T& numbers, int first, int second)
	{
		T::value_type temp = numbers[first];
		numbers[first]     = numbers[second];
		numbers[second]    = temp;
	}



#ifdef TESTING
	static void quick_sort_test()
	{
		using namespace N2B_Algo;
		std::cout << "quick_sort_test():" << std::endl << std::endl;
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
		Quick_Sort<std::vector<int>> sort;

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
		Quick_Sort<std::vector<double>> sort_d;

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