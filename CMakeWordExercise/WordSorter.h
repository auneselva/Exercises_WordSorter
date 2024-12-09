#pragma once
#include <iostream>
#include <map>
#include <unordered_map>

class WordSorter {
public:
	static void CountWords(std::string& Text, std::unordered_map<std::string, uint32_t>& OutWords);
	static void SortWordsByFrequency(std::unordered_map<std::string, uint32_t>& InWordsList);
	static void SortWordsAlphabetically(std::unordered_map<std::string, uint32_t>& InWordsList); //by ASCII actually - for now
};