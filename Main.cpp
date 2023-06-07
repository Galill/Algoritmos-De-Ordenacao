#include "FileReader.h"
#include "SortingAlgorithms.h"

using namespace std;

int main() {
	FileReader file;
	SortingAlgorithms sort;

	file.readFile();
	sort.RunAlgorithms();

	return 0;
}
