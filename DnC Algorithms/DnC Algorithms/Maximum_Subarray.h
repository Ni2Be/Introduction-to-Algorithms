pragma once

#include <vector>
namespace N2B_Algo
{
	template <class T>
	class Maximum_Subarray
	{
	public:
		Maximum_Subarray() {}

		T find_max_subarray(const T& numbers);

		void find_max_subarray(const T& numbers, int& l, int& h);

	private:
		typename T::value_type max_subarray(const T& numbers, int& l, int& h);

		typename T::value_type max_crossing_subarry(const T& numbers, int& l, int m, int& h);
	};


	template <class T>
	T Maximum_Subarray<T>::find_max_subarray(const T& numbers)
	{
		int l = 0, h = numbers.size() - 1;
		max_subarray(numbers, l, h);
		return T(numbers.begin() + l, numbers.begin() + h + 1);
	}

	template <class T>
	void Maximum_Subarray<T>::find_max_subarray(const T& numbers, int& l, int& h)
	{
		l = 0, h = numbers.size() - 1;
		max_subarray(numbers, l, h);
	}

	template <class T>
	typename T::value_type Maximum_Subarray<T>::max_subarray(const T& numbers, int& l, int& h)
	{
		if (h <= l)
			return numbers[l];
		int m = (l + h) / 2;
		//find max left subarray
		int l_l = l, l_h = m;
		T::value_type l_sum = max_subarray(numbers, l_l, l_h);
		//find max right subarray
		int r_l = m + 1, r_h = h;
		T::value_type r_sum = max_subarray(numbers, r_l, r_h);
		//find max crossing subarray
		int c_l = l, c_h = h;
		T::value_type c_sum = max_crossing_subarry(numbers, c_l, m, c_h);

		//return max array
		if (l_sum >= r_sum && l_sum >= c_sum)
		{
			l = l_l;
			h = l_h;
			return l_sum;
		}
		else if (r_sum >= c_sum)
		{
			l = r_l;
			h = r_h;
			return r_sum;
		}
		else
		{
			l = c_l;
			h = c_h;
			return c_sum;
		}
	}

	template <class T>
	typename T::value_type Maximum_Subarray<T>::max_crossing_subarry(const T& numbers, int& l, int m, int& h)
	{
		T::value_type sum = 0;
		T::value_type l_sum = numbers[m];
		for (int i = m; i >= 0; i--)
		{
			sum += numbers[i];
			if (sum >= l_sum)
			{
				l_sum = sum;
				l = i;
			}
		}

		sum = 0;
		T::value_type r_sum = numbers[m + 1];
		for (int i = m + 1; i <= h; i++)
		{
			sum += numbers[i];
			if (sum >= r_sum)
			{
				r_sum = sum;
				h = i;
			}
		}
		return l_sum + r_sum;
	}


#ifdef TESTING
	static void max_subarray_test()
	{
		Maximum_Subarray<std::vector<int>> max_sub;

		//rand seq
		std::cout << "rand seq\n";
		Random_Int_Sequence_Generator<std::vector<int>> rand_seq_gen(10, -5, 5);

		for (auto i : rand_seq_gen.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		//find max new vec
		std::vector<int> max_sub_vec = max_sub.find_max_subarray(rand_seq_gen.numbers());
		for (auto i : max_sub_vec)
			std::cout << i << " ";

		//find max indices
		int l, h;
		max_sub.find_max_subarray(rand_seq_gen.numbers(), l, h);
		std::cout << "\nindices: " << l << ", " << h << std::endl;

		//---------------------------------------------------------------------------------
		std::cout << std::endl;
		//fix seq
		std::cout << "fix seq\n";
		std::vector<int> test_vec = { -1, -2, -2, -2, -9, -4, -7, -1, -3, -5 };

		for (auto i : test_vec)
			std::cout << i << " ";
		std::cout << std::endl;

		//find max new vec
		std::vector<int> max_sub_test_vec = max_sub.find_max_subarray(test_vec);

		for (auto i : max_sub_test_vec)
			std::cout << i << " ";

		//find max indices
		max_sub.find_max_subarray(max_sub_test_vec, l, h);
		std::cout << "\nindices: " << l << ", " << h << std::endl;


		//---------------------------------------------------------------------------------
		std::cout << std::endl;
		Maximum_Subarray<std::vector<double>> max_real_sub;
		//rand seq
		std::cout << "rand real seq\n";
		Random_Real_Sequence_Generator<std::vector<double>> rand_real_seq_gen(10, -5, 5);

		for (auto i : rand_real_seq_gen.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		//find max new vec
		std::vector<double> max_sub_real_vec = max_real_sub.find_max_subarray(rand_real_seq_gen.numbers());
		for (auto i : max_sub_real_vec)
			std::cout << i << " ";

		//find max indices
		max_real_sub.find_max_subarray(rand_real_seq_gen.numbers(), l, h);
		std::cout << "\nindices: " << l << ", " << h << std::endl;

		std::cout << std::endl;
	}
#endif // TESTING
}
