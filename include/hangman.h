#ifndef HANGMAN_H
#define HANGMAN_H
#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>

class hangman {

public:

	std::vector<std::string> words;
	std::vector<std::string> possible_words;

	void read_dictionary(const std::string &path) {

		std::ifstream dictionary(path);

		std::copy(
			std::istream_iterator<std::string>(dictionary),
			std::istream_iterator<std::string>(),
			std::back_inserter(words)
		);
	}

	std::vector<std::string> filter_width(
		const std::vector<std::string> &all_words,
		unsigned length
	) {
		std::vector<std::string> result;

		std::copy_if(
			std::begin(words),
			std::end(words),
			std::begin(result),
			[&length](const std::string &s) {
				return (s.length() == length);
			}
		);

		return result;
	}

	std::vector<std::string> filter_match(
		const std::vector<std::string> &all_words,
		const std::string &pattern,
		char wildcard = '*'
	) {
		std::vector<std::string> result;

		for (const std::string &w: all_words) {

			bool match = true;

			if (pattern.length() != w.length()) {
				continue;
			}

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

	std::map<char, unsigned> initialize_character_frequency() {

		std::map<char, unsigned> result;

		for (unsigned i = 'a'; i < 'z'; ++i) {
			result.find(i)->second = 0;
		}

		return result;
	}

	std::map<char, unsigned> count_character_frequency(
		const std::vector<std::string> &all_words
	) {
		std::map<char, unsigned> result = initialize_character_frequency();

		for (const std::string &w : all_words) {

			bool checked[26] = { false };

			for (char c: w) {

				if (checked[c - 'a']) { continue; }
				checked[c - 'a'] = true;

				result.find(c)->second++;
			}
		}

		return result;
	}
};

#endif // HANGMAN_H
