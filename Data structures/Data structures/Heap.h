#pragma once
#include <vector>

namespace N2B_Algo
{
	template <class T>
	class Max_Heap
	{
	public:
		Max_Heap(const T& input)
			:
			m_numbers(input.begin(), input.end())
		{
			build_heap();
		}

		void                   insert(typename T::value_type key);
		typename T::value_type extract_max();

		std::vector<typename T::value_type>& numbers() { return m_numbers; }
	private:
		std::vector<typename T::value_type> m_numbers;

		inline int parent(int child)   { return (child - 1) / 2; }
		inline int l_child(int parent) { return 2 * parent + 1; }
		inline int r_child(int parent) { return 2 * parent + 2; }

		void build_heap();
		void heapify(int index);
		void exchange(int first, int second);
	};

	template <class T>
	void Max_Heap<T>::insert(typename T::value_type key)
	{
		m_numbers.push_back(key);
		int index = m_numbers.size() - 1;
		int child_index;
		while (key >= m_numbers[index])
		{
			child_index = index;
			index = parent(index);
			exchange(child_index, index);
			if (index == 0)
				break;
		}
	}

	//wont check if the heap is empty
	template <class T>
	typename T::value_type Max_Heap<T>::extract_max()
	{
		T::value_type max = m_numbers[0];
		exchange(0, m_numbers.size() - 1);
		m_numbers.pop_back();
		heapify(0);
		return max;
	}


	template <class T>
	void Max_Heap<T>::build_heap()
	{
		for (int i = m_numbers.size() / 2; i >= 0; i--)
		{
			heapify(i);
		}
	}

	template <class T>
	void Max_Heap<T>::heapify(int index)
	{
		int largest = index;
		int l = l_child(index);
		int r = r_child(index);
		if (l < m_numbers.size() && m_numbers[l] > m_numbers[largest])
			largest = l;
		if (r < m_numbers.size() && m_numbers[r] > m_numbers[largest])
			largest = r;
		if (largest != index)
		{
			exchange(largest, index);
			heapify(largest);
		}
	}

	template <class T>
	void Max_Heap<T>::exchange(int first, int second)
	{
		T::value_type temp = m_numbers[first];
		m_numbers[first] = m_numbers[second];
		m_numbers[second] = temp;
	}

#ifdef TESTING
	static void max_heap_test()
	{
		Unsorted_Sequence_Generator<std::vector<int>> unsorted_seq(10, 0);

		for (auto i : unsorted_seq.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		Max_Heap<std::vector<int>> max_heap(unsorted_seq.numbers());

		for (auto i : max_heap.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		max_heap.insert(10);
		for (auto i : max_heap.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		int max = max_heap.extract_max();
		std::cout << "max: " << max << std::endl;
		for (auto i : max_heap.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

	}
#endif // TESTING

}