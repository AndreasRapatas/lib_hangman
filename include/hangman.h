#ifndef HANGMAN_H
#define HANGMAN_H
#pragma once

#include <vector>
#include <map>
#include <experimental/optional>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>

#include <cassert>

std::vector<std::string> read_dictionary(const std::string &path);

std::vector<std::string> filter_length(
	const std::vector<std::string> &dictionary,
	unsigned length
);

std::vector<std::string> filter_pattern(
	const std::vector<std::string> &dictionary,
	const std::string &pattern,
	char wildcard = '*'
);

std::map<char, unsigned> count_character_frequency(
	const std::vector<std::string> &dictionary,
	const std::string &pattern = ""
);

std::vector<char> frequency_to_array(
	const std::map<char, unsigned> &character_frequency
);

std::experimental::optional<char> get_next_char(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
);

std::experimental::optional<char> get_next_vowel(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
);

std::experimental::optional<char> get_next_constant(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
);

std::experimental::optional<std::vector<unsigned>> find_char_positions(
	const std::vector<std::string> &dictionary,
	char c
);

std::string remove_pattern(
	const std::string &word,
	const std::string &pattern
	, char wildcard = '*'
);

std::vector<std::string> must_contain(
	const std::vector<std::string> &dictionary,
	const std::string &pattern,
	char c
);

std::vector<std::string> must_not_contain(
	const std::vector<std::string> &dictionary,
	const std::string &pattern,
	char c
);


#endif // HANGMAN_H
