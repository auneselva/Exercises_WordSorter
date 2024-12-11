#pragma once
#include <iostream>
#include <map>
#include <unordered_map>

class WordSorter {
public:
	static std::unordered_map<std::string, uint32_t> CountWords(std::string& Text);
	static std::vector<std::pair<std::string, uint32_t>> SortWordsByFrequency(std::unordered_map<std::string, uint32_t>& InWordsList);
	static std::vector<std::pair<std::string, uint32_t>> SortWordsAlphabetically(std::unordered_map<std::string, uint32_t>& InWordsList);
};