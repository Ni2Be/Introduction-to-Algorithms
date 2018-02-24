#include <vector>


namespace N2B_Search
{
	template <class T>
	class Linear_Search
	{
	public:
		Linear_Search()
		{}

		template <class T>
		int search(T container, typename T::value_type key)
		{
			unsigned int index = 0;
			for (; index < container.size(); index++)
			{
				if (container[index] == key)
					break;
			}
			return index;
		}
	};


#ifdef TESTING
	static void lin_search_test()
	{
		Linear_Search<std::vector<int>> linear_search;
		N2B_Sort::Insertion_Sort<int> insertion_sort;
		N2B_Algo::Unsorted_Sequence_Generator<std::vector<int>> random_seq(10, 0);
		//insertion_sort.sort(random_seq.numbers);

		for (auto i : random_seq.numbers())
			std::cout << i << " ";
		std::cout << std::endl;

		auto index = linear_search.search(random_seq.numbers(), 5);

		std::cout << "found " << random_seq.numbers()[index] << " at: " << index << std::endl;


	}
#endif // TESTING

}
