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

enum class Mode {
	HANGMAN,
	CROSSWORD
};

class Hangman {

	std::vector<std::string> dictionary;
	std::vector<std::string> possible_words;
	Mode mode;

public:

	Hangman(const Mode m = Mode::HANGMAN) : mode(m) {}

	void set_mode(const Mode &m) { mode = m; }


	void read_dictionary(const std::string &path) {

		std::ifstream dictionary_file(path);

		std::copy(
			std::istream_iterator<std::string>(dictionary_file),
			std::istream_iterator<std::string>(),
			std::back_inserter(dictionary)
		);
	}

	std::vector<std::string> filter_width(
		const std::vector<std::string> &dictionary,
		unsigned length
	) {
		std::vector<std::string> result;

		std::copy_if(
			std::begin(dictionary),
			std::end(dictionary),
			std::begin(result),
			[&length](const std::string &s) {
				return (s.length() == length);
			}
		);

		return result;
	}

	std::vector<std::string> filter_match(
		const std::vector<std::string> &dictionary,
		const std::string &pattern,
		char wildcard = '*'
	) {
		std::vector<std::string> result;

		for (const std::string &w: dictionary) {

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
		const std::vector<std::string> &dictionary
	) {
		std::map<char, unsigned> result = initialize_character_frequency();

		for (const std::string &w : dictionary) {

			bool checked[26] = { false };

			for (char c: w) {

				if (checked[c - 'a']) { continue; }
				checked[c - 'a'] = true;

				result.find(c)->second++;
			}
		}

		return result;
	}

	std::vector<std::pair<char, unsigned>> sort_chars(
		const std::map<char, unsigned> &character_frequency
	) {

		std::vector<std::pair<char, unsigned>> result(
			std::begin(character_frequency),
			std::end(character_frequency)
		);

		std::sort(
			std::begin(result),
			std::end(result),
			[](
				const std::pair<char, unsigned> &lhs,
				const std::pair<char, unsigned> &rhs
			) -> bool {
				return lhs.second < rhs.second;
			}
		);

		return result;
	}

	std::experimental::optional<char> get_next_vowel(
		const std::map<char, unsigned> &character_frequency
	) {

		std::string vowels = "aeiouy";

		for (const std::pair<char, unsigned> &p : sort_chars(character_frequency)) {
			if (vowels.find(p.first) != std::string::npos) {
				return p.first;
			}
		}

		return std::experimental::nullopt;
	}

	std::experimental::optional<char> get_next_constant(
		const std::map<char, unsigned> &character_frequency
	) {

		std::string constants = "bcdfghjklmnpqrstvwxz";

		for (const std::pair<char, unsigned> &p : sort_chars(character_frequency)) {
			if (constants.find(p.first) != std::string::npos) {
				return p.first;
			}
		}

		return std::experimental::nullopt;
	}
};

#endif // HANGMAN_H
