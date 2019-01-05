#include <catch2/catch.hpp>

#include "../include/hangman.h"

SCENARIO("contains") {

	GIVEN("'abcd', 'abad', 'xbcd'") {

		std::vector<std::string> dictionary {"abcd", "abad", "xbcd"};

		WHEN("must_contain('a')") {

			auto contains = must_contain(dictionary, 'a');

			THEN("contains = 'abcd', 'abad'") {

				REQUIRE(contains.size() == 2);
				REQUIRE(contains[0] == "abcd");
				REQUIRE(contains[1] == "abad");
			}
		}

		WHEN("must_not_contain('a')") {

			auto contains = must_not_contain(dictionary, 'a');

			THEN("contains = 'xbcd'") {

				REQUIRE(contains.size() == 1);
				REQUIRE(contains[0] == "xbcd");
			}
		}

		WHEN("must_contain('ab**', 'a')") {

			auto contains = must_contain(dictionary, 'a', "ab**");

			THEN("contains = 'abad'") {

				REQUIRE(contains.size() == 1);
				REQUIRE(contains[0] == "abad");
			}
		}

		WHEN("must_not_contain('ab**', 'a')") {

			auto contains = must_not_contain(dictionary, 'a', "ab**");

			THEN("contains = 'abcd', 'xbcd'") {

				REQUIRE(contains.size() == 2);
				REQUIRE(contains[0] == "abcd");
				REQUIRE(contains[1] == "xbcd");
			}
		}
	}
}
