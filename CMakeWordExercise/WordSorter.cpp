#include "WordSorter.h"
#include <vector>
#include <algorithm>

std::unordered_map<std::string, uint32_t> WordSorter::CountWords(std::string& Text) {

	uint32_t firstLetterIndex = 0;
	uint32_t wordLength = 0;
	std::unordered_map<std::string, uint32_t> OutWords;
	for (size_t i = 0; i < Text.length(); i++) {
		if (std::isspace(Text.at(i)) || (std::ispunct(Text.at(firstLetterIndex)) && i - firstLetterIndex == 0) || i == Text.length() - 1) {
			wordLength = i - firstLetterIndex; //size_t -> uint32_t ?
			if (i == Text.length() - 1 && !std::isspace(Text.at(i)))
				wordLength++;
			if (wordLength < 1) {
				firstLetterIndex = i + 1;
				continue;
			}
			std::string word = Text.substr(firstLetterIndex, wordLength);
			while (word.length() > 0 && std::ispunct(word[word.length() - 1])) {
				word.pop_back();
			}
			if (word.length() == 0) {
				firstLetterIndex = i + 1;
				continue;
			}
			std::transform(word.begin(), word.end(), word.begin(),
				[](unsigned char l) {
					return std::tolower(l);
				});
			if (OutWords.contains(word))
				OutWords.insert_or_assign(word, OutWords.at(word) + 1);
			else
				OutWords.emplace(word, 1);
			firstLetterIndex = i + 1;
		}
	}
	return OutWords;
}

std::vector<std::pair<std::string, uint32_t>> WordSorter::SortWordsByFrequency(std::unordered_map<std::string, uint32_t>& InWordsList) {

	std::vector<std::pair<std::string, uint32_t>> vec(InWordsList.begin(), InWordsList.end());

	std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, uint32_t>& a, const std::pair<std::string, uint32_t>& b) {
		if (a.second == b.second)
			return a.first < b.first; //sort alphabetically the words with the same frequency
		return a.second > b.second;
		});
	return vec;
}

std::vector<std::pair<std::string, uint32_t>> WordSorter::SortWordsAlphabetically(std::unordered_map<std::string, uint32_t>& InWordsList) {

	std::vector<std::pair<std::string, uint32_t>> vec(InWordsList.begin(), InWordsList.end());

	std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, uint32_t>& a, const std::pair<std::string, uint32_t>& b) {
		return a.first < b.first; //assuming lower-case
		});
	return vec;
}