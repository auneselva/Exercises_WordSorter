
#include "CMakeWordExerciseMain.h"
#include "WordSorter.h"
#include "WordSorterTest.h"
#include "Timer.h"

template <typename Container>
void PrintContainer(const Container& container) {
	for (const auto& pair : container) {
		std::cout << pair.first << ": " << pair.second << "\n";
	}
	std::cout << "\n\n";
}

int main() {
	std::cout << "Hello, I'm a word sorter.\n\n";

	WordSorterTest test;
	Timer timer;
	for (std::string& example : test.examples) {

		timer.Reset();
		std::cout << "Example: |" << example << "|\n\n";
		
		std::unordered_map<std::string, uint32_t> WordsCount = WordSorter::CountWords(example);
		std::cout << "Unsorted key-value pairs:\n";
		PrintContainer(WordsCount);

		std::vector<std::pair<std::string, uint32_t>> WordsSorted = WordSorter::SortWordsByFrequency(WordsCount);
		std::cout << "Sorted key-value pairs by value:\n";
		PrintContainer(WordsSorted);

		WordsSorted = WordSorter::SortWordsAlphabetically(WordsCount);
		std::cout << "Sorted key-value pairs alphabetically:\n";
		PrintContainer(WordsSorted);

		std::cout << "\nElapsedMilis: " << timer.ElapsedMillis() << "ms. \n\n";
	}
	
	return 0;
}
