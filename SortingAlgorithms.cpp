#include <iostream>
#include <vector>
#include "SortingAlgorithms.h"

using namespace std;

void SortingAlgorithms::SelectionSort(std::vector<int> Vector) {
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

	for (int k = 0; k < Vector.size(); k++) {
		cout << Vector[k] << "\n" << endl;
	}
}

void SortingAlgorithms::BubbleSort(std::vector<int> Vector) {
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

	for (int k = 0; k < Vector.size(); k++) {
		cout << Vector[k] << "\n" << endl;
	}
}

void SortingAlgorithms::InsertionSort(std::vector<int> Vector) {
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

	for (int k = 0; k < Vector.size(); k++) {
		cout << Vector[k] << "\n" << endl;
	}
}

void SortingAlgorithms::MergeSort() {

}

void SortingAlgorithms::QuickSort() {

}