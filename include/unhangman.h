/**
 * @file
 * @brief Declarations of all the functions
 */

/**
 * @mainpage Welcome to unhangman
 * @section intro_sec Introduction
 *
 * This is a collection of functions designed to help you build a crossword / hangman game / solver.
 *
 * @section usage Usage
 *
 * See the include/unhangman.h in the files tab.
 */

#ifndef HANGMAN_H
#define HANGMAN_H
#pragma once

#include <string>
#include <vector>
#include <map>
#include <experimental/optional>

/**
 * @brief Fill a vector of strings from a file
 *
 * @param path Where to find the dictinary
 *
 * @return vector<string> containing lines of the dictionary
 */
std::vector<std::string> read_dictionary(const std::string &path);

/**
 * @brief Filters out words that don't match the desired length
 *
 * @param dictionary The words to check
 * @param length The required length
 *
 * @return A vector<string> of words that match the length
 */
std::vector<std::string> filter_length(
	const std::vector<std::string> &dictionary,
	unsigned length
);

/**
 * @brief Filter words that dont match the provided pattern
 *
 * @param dictionary The words to check
 * @param pattern A string to match all words. E.g. "pot*to"
 * @param wildcard The character to ignore in the pattern. Default '*'
 *
 * @return A vector<string> of words that match the pattern
 */
std::vector<std::string> filter_pattern(
	const std::vector<std::string> &dictionary,
	const std::string &pattern,
	char wildcard = '*'
);

/**
 * @brief Counts the appearance of characters in words. Each character is
 * counted once per word. If it's possition matches the pattern's, it's ignored
 *
 * @param dictionary The words to check
 * @param pattern The pattern to ignore
 *
 * @return A map of characters and their appearance counters
 */
std::map<char, unsigned> count_character_frequency(
	const std::vector<std::string> &dictionary,
	const std::string &pattern = ""
);

/**
 * @brief Transforms a map of characters and their appearance counters
 * to an array sorted by the appearance counter
 *
 * @param character_frequency A map of characters and their appearance counters
 *
 * @return An array sorted by the appearance counter
 */
std::vector<char> frequency_to_array(
	const std::map<char, unsigned> &character_frequency
);

/**
 * @brief Get the character that apeared in the most words
 *
 * @param char_array Characters sorted by appearance frequency
 * @param ignore Characters to ignore if they come up
 *
 * @return The next possible character. if there are none returns nullopt
 */
std::experimental::optional<char> get_next_char(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
);

/**
 * @brief Get the vowel that apeared in the most words
 *
 * @param char_array Characters sorted by appearance frequency
 * @param ignore Characters to ignore if they come up
 *
 * @return The next possible vowel character. if there are none returns nullopt
 */
std::experimental::optional<char> get_next_vowel(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
);

/**
 * @brief Get the constatnt that apeared in the most words
 *
 * @param char_array Characters sorted by appearance frequency
 * @param ignore Characters to ignore if they come up
 *
 * @return The next possible constant character.
 * if there are none returns nullopt
 */
std::experimental::optional<char> get_next_constant(
	const std::vector<char> &char_array,
	const std::string &ignore = ""
);

/**
 * @brief If a character appears in the same possitions in all provided words,
 * it returns their positions
 *
 * @param dictionary The words to check
 * @param c The character to find positions
 *
 * @return A vector<unsigned> with the positions of the character
 */
std::experimental::optional<std::vector<unsigned>> find_char_positions(
	const std::vector<std::string> &dictionary,
	char c
);

/**
 * @brief Removes the characters of pattern from word
 *
 * @param word The word you need to clean up
 * @param pattern The characters you want removed from word
 * @param wildcard If this character is in the pattern it will
 * not be removed from word
 *
 * @return The word but without any characters of the pattern
 */
std::string remove_pattern(
	const std::string &word,
	const std::string &pattern,
	char wildcard = '*'
);

/**
 * @brief Returns a vector of words that contain the specified character,
 * ignoring it's appearence in the pattern (if provided)
 *
 * @param dictionary A vector of words that you are currently choosing from
 * @param c The character that the words must contain
 * @param pattern The pattern wich should be ignored in all words
 *
 * @return a vector of words that contain the specified character.
 */
std::vector<std::string> must_contain(
	const std::vector<std::string> &dictionary,
	char c,
	const std::string &pattern = ""
);

/**
 * @brief Returns a vector of words that don't contain the specified character,
 * ignoring it's appearence in the pattern (if provided)
 *
 * @param dictionary A vector of words that you are currently choosing from
 * @param c The character that the words must not contain
 * @param pattern The pattern wich should be ignored in all words
 *
 * @return a vector of words that don't contain the specified character.
 */
std::vector<std::string> must_not_contain(
	const std::vector<std::string> &dictionary,
	char c,
	const std::string &pattern = ""
);


#endif // HANGMAN_H
