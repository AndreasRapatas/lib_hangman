#include <iostream>
#include <string>

using namespace std;

#include "../include/hangman.h"

int main() {

	string path = "words.txt";

	auto dictionary = read_dictionary(path);

	cout << dictionary.size() << " words found\n";

	cout << "Length of the word: ";
	unsigned length = 0;
	cin >> length;

	cout << "Type the known chars, * for unknown\n";
	string pattern;
	cin >> pattern;

	if (pattern.size() != length) {
		return 0;
	}

	auto matching = filter_match(filter_width(dictionary, length), pattern);

	for (const auto &w : matching) {
		cout << w << '\n';
	}

	auto frequency = count_character_frequency(matching);
	auto sorted_chars = frequency_to_array(frequency);
	if (auto v = get_next_vowel(sorted_chars)) {
		cout << "Most common vowel: " << v.value() << '\n';
	}
	if (auto c = get_next_constant(sorted_chars)) {
		cout << "Most common constant: " << c.value() << '\n';
	}


	return 0;
}
