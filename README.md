# lib_hangman
A single-header C++ library providing functions for a hangman or crossword solver.

```c++
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
```
