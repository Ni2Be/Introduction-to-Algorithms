#pragma once
#include <vector>
#include <random>
#include <iostream>

#include "../../Sorting/Sorting/Insertion_Sort.h"
#include "Linear_Search.h"
//not optimized

namespace N2B_Search
{
	class Nth_Min
	{
	public:
		Nth_Min() {}

		int find(const std::vector<int> numbers, int k)
		{
			std::vector<int> copy_nums(numbers);
			int index = find(copy_nums, 0, copy_nums.size() - 1, k);
			return copy_nums[index];
		}

		int find(std::vector<int>& numbers, int l, int h, int k)
		{
			if (l == h)
				return l;
			Linear_Search<std::vector<int>> search;

			int pivot       = select_pivot(numbers, l, h);
			int pivot_index = search.search(numbers, pivot);
			int index       = selected_partition(numbers, l, h, pivot_index);

			if (k - 1 == index)
				return index;
			if (k - 1 < index)
				return find(numbers, l, index - 1, k);
			else
				return find(numbers, index + 1, h, k);
		}

		int select_pivot(std::vector<int>& numbers, int l, int h)
		{
			N2B_Sort::Insertion_Sort<std::vector<int>> sort;
			std::vector<int>						   pivots;

			if (h - l >= 1)
			{
				while (l + 5 <= h)
				{
					std::vector<int> pack(numbers.begin() + l, numbers.begin() + l + 5);
					sort.sort(pack);
					pivots.push_back(pack[2]);
					l += 5;
				}
				//if anything is left add it
				if (l != h)
				{
					std::vector<int> pack(numbers.begin() + l, numbers.begin() + l + (h - l));
					sort.sort(pack);
					pivots.push_back(pack[(pack.size()) / 2]);
				}
				return select_pivot(pivots, 0, pivots.size() - 1);
			}
			else
				return numbers[0];
		}

		int selected_partition(std::vector<int>& numbers, int l, int h, int pivot_index)
		{
			int pivot = numbers[pivot_index];
			exchange(numbers, pivot_index, h);

			int smaller_index = l;

			for (int i = l; i <= h - 1; i++)
			{
				if (numbers[i] <= pivot)
					exchange(numbers, smaller_index++, i);
			}

			exchange(numbers, smaller_index, h);

			return smaller_index;
		}

		void exchange(std::vector<int>& numbers, int first, int second)
		{
			int temp = numbers[first];
			numbers[first] = numbers[second];
			numbers[second] = temp;
		}

	};

	static void min_max_test()
	{
		std::vector<int> vec = { 3,6,7,1,-1,4,5, 8 ,45, -4, 32, -22, 21, 13, 2,57};
		int k = 7;
		std::cout << "k: " << k << ", numbers:\n";
		for (auto i : vec)
			std::cout << i << " ";
		std::cout << std::endl;
		
		Nth_Min nth_min;
		int n_val = nth_min.find(vec, k);


		std::cout << "found: " << n_val;
		std::cout << std::endl;

	}

}


