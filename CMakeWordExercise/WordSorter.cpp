#include "WordSorter.h"
#include <vector>
#include <algorithm>

template <typename Container>
void printContainer(const Container& container) {
	for (const auto& pair : container) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
}

void WordSorter::CountWords(std::string& Text, std::unordered_map<std::string, uint32_t>& OutWords)
{
	uint32_t firstLetterIndex = 0;
	uint32_t wordLength = 0;
	for (size_t i = 0; i < Text.length(); i++) {

		if (std::isspace(Text.at(i)) || i == Text.length() - 1) { // || std::ispunct)
			wordLength = i - firstLetterIndex; //size_t -> uint32_t ?
			if (i == Text.length() - 1 && !std::isspace(Text.at(i)))
				wordLength++;
			if (wordLength < 1) {
				firstLetterIndex = i + 1;
				continue;
			}
			std::string word = Text.substr(firstLetterIndex, wordLength);
			if (OutWords.contains(word))
				OutWords.insert_or_assign(word, OutWords.at(word) + 1);
			else
				OutWords.emplace(word, 1);
			firstLetterIndex = i + 1;
		}
	}
	
	std::cout << "Unsorted key-value pairs:\n";
	printContainer(OutWords);
	std::cout << "\n\n";
}
void WordSorter::SortWordsByFrequency(std::unordered_map<std::string, uint32_t>& InWordsList)
{
	std::vector<std::pair<std::string, uint32_t>> vec(InWordsList.begin(), InWordsList.end());

	std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, uint32_t>& a, const std::pair<std::string, uint32_t>& b) {
		return a.second > b.second;
		});

	std::cout << "Sorted key-value pairs by value:\n";
	printContainer(vec);
	std::cout << "\n\n";
}

void WordSorter::SortWordsAlphabetically(std::unordered_map<std::string, uint32_t>& InWordsList) {
	std::vector<std::pair<std::string, uint32_t>> vec(InWordsList.begin(), InWordsList.end());

	std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, uint32_t>& a, const std::pair<std::string, uint32_t>& b) {
		return a.first < b.first; //case-insensitive
		});

	std::cout << "Sorted key-value pairs alphabetically:\n";
	printContainer(vec);
	std::cout << "\n\n";
}