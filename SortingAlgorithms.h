#pragma once
#include <vector>

class SortingAlgorithms {

	public:
		static std::vector<int> Vector;

		void SelectionSort(std::vector<int> Vector);

		void BubbleSort(std::vector<int> Vector);

		void InsertionSort(std::vector<int> Vector);

		void MergeSort(std::vector<int>& Vector, std::vector<int>& Vector_aux, int Start, int End);

		void Merge(std::vector<int>& Vector, std::vector<int>& Vector_aux, int Start, int middle, int End);

		void QuickSort(std::vector<int>& Vector, int Start, int End);

		int Partition(std::vector<int>& Vector, int Start, int End);

		void printa(std::vector<int> Vector);

		void RunAlgorithms();
};
