/*
Sequence Generator:

Generates random sequences into a container structure the structure 
needs random access to its members and must not be const.

The std container vector and deque fulfill the needed requirements.
*/
#pragma once
#include <random>
#include <algorithm>
#include <numeric>

namespace N2B_Algo
{
	/*
	This is just a base class, use
	Unsorted_Sequence_Generator <container type>
	or
	Random_Real_Sequence_Generator <container type>
	or
	Random_Int_Sequence_Generator <container type> instead
	*/
	template <class T>
	class Sequence_Generator
	{
	public:
		T& numbers() { return m_numbers; }
	protected:
		T m_numbers;

		Sequence_Generator()
		{}
		Sequence_Generator(unsigned int count)
			:
			m_numbers(count)
		{}
		
		std::random_device					m_rd;
	};


	/*
	This is just a base class, use
	Random_Real_Sequence_Generator <container type>
	or
	Random_Int_Sequence_Generator <container type> instead
	*/
	template <class T, class R>
	class Random_Sequence_Generator : public Sequence_Generator<T>
	{
	protected:
		Random_Sequence_Generator(
			unsigned int			count,
			typename T::value_type  min,
			typename T::value_type  max)
			:
			Sequence_Generator(count),
			m_dist(min, max)
		{
			for (unsigned int i = 0; i < count; i++)
			{
				m_numbers[i] = m_dist(m_rd);
			}
		}
		R	m_dist;
	};

	/*
	Random_Real_Sequence_Generator<container type>:
	Generates random real numbers into its member "m_numbers"
	for Random_Real_Sequence_Generator<double>(10, -5, 5)
	possible m_numbers:
	[-3.40339, 4.76768, -0.852059, 0.501342, 2.94599, 4.39577, 0.00839807, 0.583905, -4.7037, 4.86458]
	*/
	template <class T>
	class Random_Real_Sequence_Generator :
		public Random_Sequence_Generator<T, std::uniform_real_distribution<typename T::value_type>>
	{
	public:
		Random_Real_Sequence_Generator(
			unsigned int			count,
			typename T::value_type  min,
			typename T::value_type  max)
			:
			Random_Sequence_Generator(count, min, max)
		{}
	};

	/*
	Random_Int_Sequence_Generator<container type>:
	Generates random real numbers into its member "m_numbers"
	for Random_Int_Sequence_Generator<double>(10, -5, 5)
	possible m_numbers:
	[4, 4, 5, 3, -4, -5, 0, -2, -4, -2]
	*/
	template <class T>
	class Random_Int_Sequence_Generator :
		public Random_Sequence_Generator<T, std::uniform_int_distribution<typename T::value_type>>
	{
	public:
		Random_Int_Sequence_Generator(
			unsigned int			count,
			typename T::value_type  min,
			typename T::value_type  max)
			:
			Random_Sequence_Generator(count, min, max)
		{}
	};

	/*
	Unsorted_Sequence_Generator<container type>:
	Generates random real numbers into its member "m_numbers"
	for Unsorted_Sequence_Generator<int>(10, -5)
	possible m_numbers:
	[3, -4, 4, -3, -5, 0, 2, -2, -1, 1]
	for Unsorted_Sequence_Generator<double>(10, -5, 0.2)
	possible m_numbers:
	[-3.4, -4.8, -3.2, -4.6, -5, -4, -3.6, -4.4, -4.2, -3.8]
	*/
	template <class T>
	class Unsorted_Sequence_Generator : public Sequence_Generator<T>
	{
	public:
		Unsorted_Sequence_Generator(
			unsigned int			count,
			typename T::value_type  min,
			typename T::value_type  increment_by = 1
			)
			:
			Sequence_Generator(count),
			m_rand_engine(m_rd())
		{
			min -= increment_by;
			std::generate(m_numbers.begin(), m_numbers.end(),
				[min, increment_by]() mutable { return min += increment_by; });
			std::shuffle(m_numbers.begin(), m_numbers.end(), m_rand_engine);
		}
		
	private:
		std::mt19937 m_rand_engine;
	};

#ifdef TESTING
	static void rand_seq_gen_test()
	{
		Random_Int_Sequence_Generator<std::vector<int>> random(10, -5, 5);


		std::cout << "Random_Real_Sequence_Generator:" << std::endl;
		for (auto i : random.numbers())
		{
			std::cout << i << ", ";
		}
		std::cout << std::endl << std::endl;

		std::cout << "Unsorted_Sequence_Generator:" << std::endl;
		Unsorted_Sequence_Generator<std::vector<double>> unsorted(10, -5, 0.2);
		for (auto i : unsorted.numbers())
		{
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}
#endif // TESTING

}
