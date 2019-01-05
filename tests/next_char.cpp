#include <catch2/catch.hpp>

#include "../include/hangman.h"

SCENARIO("next char") {

	GIVEN("array of chars 'gabce'") {

		std::vector<char> sorted {'g', 'a', 'b', 'c', 'e'};

		WHEN("get_next_char") {

			auto c = get_next_char(sorted);

			THEN("c == g") {

				REQUIRE(c.value() == 'g');
			}
		}

		WHEN("get_next_char and ignore 'g'") {

			auto c = get_next_char(sorted, "g");

			THEN("c == a") {

				REQUIRE(c.value() == 'a');
			}
		}

		WHEN("get_next_vowel") {

			auto c = get_next_vowel(sorted);

			THEN("c == a") {

				REQUIRE(c.value() == 'a');
			}
		}

		WHEN("get_next_vowel and ignore a") {

			auto c = get_next_vowel(sorted, "a");

			THEN("c == e") {

				REQUIRE(c.value() == 'e');
			}
		}

		WHEN("get_next_vowel and ignore ae") {

			auto c = get_next_vowel(sorted, "ae");

			THEN("c == nullopt") {

				REQUIRE(c.value_or(' ') == ' ');
			}
		}

		WHEN("get_next_constant") {

			auto c = get_next_constant(sorted);

			THEN("c == g") {

				REQUIRE(c.value() == 'g');
			}
		}

		WHEN("get_next_constant and ignore g") {

			auto c = get_next_constant(sorted, "g");

			THEN("c == b") {

				REQUIRE(c.value() == 'b');
			}
		}

		WHEN("get_next_constant and ignore gbc") {

			auto c = get_next_constant(sorted, "gbc");

			THEN("c == nullopt") {

				REQUIRE(c.value_or(' ') == ' ');
			}
		}
	}
}

