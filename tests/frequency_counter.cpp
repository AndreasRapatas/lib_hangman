#include <catch2/catch.hpp>

#include "../include/hangman.h"

SCENARIO("frequency counter") {

	GIVEN("a word of a's  'aaaa'") {

		std::vector<std::string> dictionary {"aaaa"};

		WHEN("counting frequency") {

			auto freq = count_character_frequency(dictionary);

			THEN("a should be 1 and all other 0") {

				for (auto p : freq) {
					if (p.first == 'a') {
						REQUIRE(p.second == 1);
					} else {
						REQUIRE(p.second == 0);
					}
				}
			}
		}
	}

	GIVEN("two words 'aaaa', 'abbb'") {

		std::vector<std::string> dictionary {"aaaa", "abbb"};

		WHEN("counting frequency") {

			auto freq = count_character_frequency(dictionary);

			THEN("a == 2, b == 1, and all other 0") {

				for (auto p : freq) {
					if (p.first == 'a') {
						REQUIRE(p.second == 2);
					} else if (p.first == 'b') {
						REQUIRE(p.second == 1);
					} else {
						REQUIRE(p.second == 0);
					}
				}
			}
		}

		WHEN("counting frequency with a pattern 'a***'") {

			auto freq = count_character_frequency(dictionary, "a***");

			THEN("a == 1, b == 1, and all other 0") {

				for (auto p : freq) {
					if (p.first == 'a') {
						REQUIRE(p.second == 1);
					} else if (p.first == 'b') {
						REQUIRE(p.second == 1);
					} else {
						REQUIRE(p.second == 0);
					}
				}
			}
		}

		WHEN("counting frequency with a pattern 'abbb'") {

			auto freq = count_character_frequency(dictionary, "abbb");

			THEN("results will be wrong because user should run filter_match beforehand") {

				for (auto p : freq) {
					REQUIRE(p.second == 0);
				}
			}
		}
	}
}

SCENARIO("frequency_to_array") {

	GIVEN("a char freqency of a=2, b=1, c=7") {

		std::map<char, unsigned> freq = {{'a', 2}, {'b', 1}, {'c', 7}};

		WHEN("frequency_to_array") {

			auto sorted = frequency_to_array(freq);

			THEN("order should be 'cab'") {

				REQUIRE(sorted[0] == 'c');
				REQUIRE(sorted[1] == 'a');
				REQUIRE(sorted[2] == 'b');
			}
		}
	}
}
