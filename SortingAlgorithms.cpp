#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "SortingAlgorithms.h"

using namespace std;
using namespace std::chrono;

std::vector<int> SortingAlgorithms::Vector;

void SortingAlgorithms::SelectionSort(std::vector<int> Vector) {
	auto start = steady_clock::now();
	int aux = 0, min = 0; 
	for (int i = 0; i < (Vector.size() - 1); i++) {
		min = i;
		for (int j = (i + 1); j < Vector.size(); j++) {
			if (Vector[j] < Vector[min]) {
				min = j;
			}
		}
		aux = Vector[min];
		Vector[min] = Vector[i];
		Vector[i] = aux;
	}
	auto end = steady_clock::now();
	auto elapsed = end - start;
	cout << "Selection Sort:\n " << duration<double>(elapsed).count() << " segundos!" << endl;
}

void SortingAlgorithms::BubbleSort(std::vector<int> Vector) {
	auto start = steady_clock::now();
	int aux = 0;
	for (int i = 0; i < (Vector.size() - 1); i++) {
		for (int j = (i + 1); j < Vector.size(); j++) {
			if (Vector[i] > Vector[j]) {
				aux = Vector[i];
				Vector[i] = Vector[j];
				Vector[j] = aux;
			}
		}
	}
	auto end = steady_clock::now();
	auto elapsed = end - start;
	cout << "Bubble Sort:\n " << duration<double>(elapsed).count() << " segundos!" << endl;
}

void SortingAlgorithms::InsertionSort(std::vector<int> Vector) {
	auto start = steady_clock::now();
	int aux = 0, atual = 0;
	for (int i = 0; i < Vector.size(); i++) {
		atual = Vector[i];
		aux = i;
		while((aux > 0) && (Vector[aux - 1] > atual)){
			Vector[aux] = Vector[aux - 1];
			aux = aux - 1;
		}
		Vector[aux] = atual;
	}
	auto end = steady_clock::now();
	auto elapsed = end - start;
	cout << "Insertion Sort:\n " << duration<double>(elapsed).count() << " segundos!" << endl;
}

void SortingAlgorithms::MergeSort(std::vector<int>& Vector, std::vector<int>& Vector_aux, int Start, int End) {
	int middle;
	if (Start < End) {
		middle = (Start + End) / 2;
		MergeSort(Vector, Vector_aux, Start, middle);
		MergeSort(Vector, Vector_aux, middle + 1, End);
		Merge(Vector, Vector_aux, Start, middle, End);
	}
}

void SortingAlgorithms::Merge(std::vector<int>& Vector, std::vector<int>& Vector_aux, int Start, int middle, int End) {
	int i = Start, j = middle + 1, k = 0;
	while ((i <= middle) && (j <= End)) {
		if (Vector[i] <= Vector[j]) {
			Vector_aux[k] = Vector[i];
			i++;
		}
		else {
			Vector_aux[k] = Vector[j];
			j++;
		}
		k++;
	}
	while (i <= middle) {
		Vector_aux[k] = Vector[i];
		i++;
		k++;
	}
	while (j <= End) {
		Vector_aux[k] = Vector[j];
		j++;
		k++;
	}
	for (int x = 0; x < k; x++) {
		Vector[Start + x] = Vector_aux[x];
	}
}

void SortingAlgorithms::QuickSort(std::vector<int>& Vector, int Start, int End) {
	int pivo;
	if (Start < End) {
		pivo = Partition(Vector, Start, End);
		QuickSort(Vector, Start, pivo - 1);
		QuickSort(Vector, pivo + 1, End);
	}
}

int SortingAlgorithms::Partition(std::vector<int>& Vector, int Start, int End){
	int pivo = Vector[End];
	int x = Start - 1;

	for (int j = Start; j <= End - 1; j++) {
		if (Vector[j] <= pivo) {
			x++;
			std::swap(Vector[x], Vector[j]);
		}
	}
	std::swap(Vector[x + 1], Vector[End]);
	return x + 1;
} 

void SortingAlgorithms::RunAlgorithms() {
	std::vector<int> data1 = Vector;
	std::vector<int> data2 = Vector;
	std::vector<int> data3 = Vector;
	std::vector<int> Vector_aux(data2.size());

	// CÓDIGO CONCORRENTE: (Não calcula o tempo do quick sort nem do merg sort)
	/*std::thread ThreadSelectionSort(&SortingAlgorithms::SelectionSort, this, data1);
	std::thread ThreadBubbleSort(&SortingAlgorithms::BubbleSort, this, data1);
	std::thread ThreadInsertionSort(&SortingAlgorithms::InsertionSort, this, data1);
	std::thread ThreadMergeSort(&SortingAlgorithms::MergeSort, this, std::ref(data2), std::ref(Vector_aux), 0, data2.size() - 1);
	std::thread ThreadQuickSort(&SortingAlgorithms::QuickSort, this, std::ref(data3), 0, data3.size() - 1);

	ThreadSelectionSort.join();
	ThreadBubbleSort.join();
	ThreadInsertionSort.join();
	ThreadMergeSort.join();
	ThreadQuickSort.join();*/

	// CÓDIGO PARALELO:
	SortingAlgorithms sort;
	sort.SelectionSort(Vector);
	sort.BubbleSort(Vector);
	sort.InsertionSort(Vector);
	
	auto start1 = steady_clock::now();
	sort.MergeSort(data2, Vector_aux, 0, data2.size() - 1);
	auto end1 = steady_clock::now();
	auto elapsed1 = end1 - start1;
	cout << "Merg Sort:\n " << duration<double>(elapsed1).count() << " segundos!" << endl;

	auto start2 = steady_clock::now();
	sort.QuickSort(data3, 0, data3.size() - 1);
	auto end2 = steady_clock::now();
	auto elapsed2 = end2 - start2;
	cout << "Quick Sort:\n " << duration<double>(elapsed2).count() << " segundos!" << endl;
}
