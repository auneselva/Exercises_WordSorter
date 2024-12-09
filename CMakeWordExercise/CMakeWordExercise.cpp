
#include "CMakeWordExercise.h"
#include "WordSorter.h"
#include "Test.h"

int main()
{
	std::shared_ptr<Test> test = std::make_shared<Test>();
	std::shared_ptr < std::unordered_map<std::string, uint32_t>> map = std::make_shared < std::unordered_map<std::string, uint32_t>>();
	std::cout << "Hello, I'm a word sorter.\n\n" << std::endl;

	std::cout << "Example 0: |" << test->example0 << "|\n\n";
	WordSorter::CountWords(test->example0, *map);
	WordSorter::SortWordsByFrequency(*map);
	WordSorter::SortWordsAlphabetically(*map);
	map->clear();
	
	std::cout << "Example 1: |" << test->example1 << "|\n\n";
	WordSorter::CountWords(test->example1, *map);
	WordSorter::SortWordsByFrequency(*map);
	WordSorter::SortWordsAlphabetically(*map);
	map->clear();

	std::cout << "Example 2: |" << test->example2 << "|\n\n";
	WordSorter::CountWords(test->example2, *map);
	WordSorter::SortWordsByFrequency(*map);
	WordSorter::SortWordsAlphabetically(*map);
	map->clear();

	std::cout << "Example 3: |" << test->example3 << "|\n\n";
	WordSorter::CountWords(test->example3, *map);
	WordSorter::SortWordsByFrequency(*map);
	WordSorter::SortWordsAlphabetically(*map);
	map->clear();

	std::cout << "Example 4: |" << test->example4 << "|\n\n";
	WordSorter::CountWords(test->example4, *map);
	WordSorter::SortWordsByFrequency(*map);
	WordSorter::SortWordsAlphabetically(*map);
	return 0;
}
