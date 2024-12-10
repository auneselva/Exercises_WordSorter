
#include "CMakeWordExercise.h"
#include "WordSorter.h"
#include "Test.h"
#include "Timer.h"

int main()
{
	std::cout << "Hello, I'm a word sorter.\n\n";

	Test test;
	Timer timer;
	for (std::string& example : test.examples) {

		timer.Reset();
		std::cout << "Example: " << example << "|\n\n";
		
		std::unordered_map<std::string, uint32_t> map;
		WordSorter::CountWords(example, map);
		WordSorter::SortWordsByFrequency(map);
		WordSorter::SortWordsAlphabetically(map);

		std::cout << "\nElapsedMilis: " << timer.ElapsedMillis() << "ms. \n\n";
	}
	
	return 0;
}
