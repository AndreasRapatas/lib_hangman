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

std::vector<std::string> read_dictionary(const std::string &path) {

	std::vector<std::string> result;

	std::ifstream dictionary_file(path);

	std::copy(
		std::istream_iterator<std::string>(dictionary_file),
		std::istream_iterator<std::string>(),
		std::back_inserter(result)
	);

	return result;
}

std::vector<std::string> filter_length(
	const std::vector<std::string> &dictionary,
	unsigned length
) {
	std::vector<std::string> result;

	std::copy_if(
		std::begin(dictionary),
		std::end(dictionary),
		std::back_inserter(result),
		[&length](const std::string &s) {
			return (s.length() == length);
		}
	);

	return result;
}

std::vector<std::string> filter_pattern(
	const std::vector<std::string> &dictionary,
	const std::string &pattern,
	char wildcard = '*'
) {
	std::vector<std::string> result;

	for (const std::string &w: dictionary) {

		bool match = true;

		if (pattern.length() != w.length()) { continue; }

		for (unsigned i = 0; i < w.length(); ++i) {

			if (pattern[i] == wildcard) { continue; }

			if (w[i] != pattern[i]) {
				match = false;
				break;
			}
		}

		if (match) { result.push_back(w); }
	}

	return result;
}

std::map<char, unsigned> count_character_frequency(
	const std::vector<std::string> &dictionary,
	const std::string &pattern = ""
) {
	std::map<char, unsigned> result;

	// Initialize all char frequencies to 0
	for (unsigned i = 'a'; i < 'z'; ++i) {
		result.insert({i, 0});
	}

	for (const std::string &w : dictionary) {

		bool checked[26] = { false };

		for (unsigned i = 0; i < w.size(); ++i) {

			// If we know the letter in this possition, don't count it
			if (pattern.size() != 0 && pattern[i] != '*') { continue; }

			// Check each letter once per word
			if (checked[w[i] - 'a']) { continue; }
			checked[w[i] - 'a'] = true;

			result.find(w[i])->second++;
		}
	}

	return result;
}

std::vector<char> frequency_to_array(
	const std::map<char, unsigned> &character_frequency
) {
	std::vector<std::pair<char, unsigned>> to_sort(
		std::begin(character_frequency),
		std::end(character_frequency)
	);
	to_sort.shrink_to_fit();

	std::sort(
		std::begin(to_sort),
		std::end(to_sort),
		[](
			const std::pair<char, unsigned> &lhs,
			const std::pair<char, unsigned> &rhs
		) -> bool {
			return lhs.second > rhs.second;
		}
	);

	std::vector<char> result;
	result.reserve(to_sort.size());

	for (const auto &p : to_sort) {
		result.push_back(p.first);
	}

	return result;
}

std::experimental::optional<char> get_next_char(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
) {
	for (char c : char_array) {
		if (ignore.find(c) == std::string::npos) {
			return c;
		}
	}

	return std::experimental::nullopt;
}

std::experimental::optional<char> get_next_vowel(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
) {
	std::string vowels = "aeiouy";

	for (char c : char_array) {
		if (
			vowels.find(c) != std::string::npos
			&& ignore.find(c) == std::string::npos
		) {
			return c;
		}
	}

	return std::experimental::nullopt;
}

std::experimental::optional<char> get_next_constant(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
) {
	std::string constants = "bcdfghjklmnpqrstvwxz";

	for (char c : char_array) {
		if (
			constants.find(c) != std::string::npos
			&& ignore.find(c) == std::string::npos
		) {
			return c;
		}
	}

	return std::experimental::nullopt;
}

#endif // HANGMAN_H
