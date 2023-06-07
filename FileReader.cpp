#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "FileReader.h"
#include "SortingAlgorithms.h"

using namespace std;

void FileReader::readFile() {
		ifstream file;
		string file_name, line;
		std::vector<int> test_case;
		int  i = 0, vec_size = 0;

		cout << "Arquivo: ";
		cin >> file_name;

		file.open(file_name);

		if (!file.is_open()) {
			cout << "Erro ao abrir o arquivo!" << endl;
		}

		while (getline(file, line)) {
			i = stoi(line);
			test_case.push_back(i);
		}

		file.close();

		SortingAlgorithms::Vector = test_case;
	}
