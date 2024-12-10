
#include "CMakeWordExercise.h"
#include "WordSorter.h"
#include "Test.h"
#include "Timer.h"

int main()
{
	Test test;
	std::unordered_map<std::string, uint32_t> map;
	std::cout << "Hello, I'm a word sorter.\n\n" << std::endl;

	Timer timer;
	for (std::string example : test.examples) {
		timer.Reset();

		std::cout << "Example 0: |" << example << "|\n\n";
		WordSorter::CountWords(example, map);
		WordSorter::SortWordsByFrequency(map);
		WordSorter::SortWordsAlphabetically(map);
		map.clear();

		std::cout << "\nElapsedMilis: " << timer.ElapsedMillis() << "ms. \n\n";
	}
	
	return 0;
}
