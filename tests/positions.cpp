#include <catch2/catch.hpp>

#include "../include/hangman.h"

SCENARIO("positioning") {

	GIVEN("an array 'subjective', 'subversive'") {

		std::vector<std::string> dictionary {
			"subjective",
			"subversive"
		};

		WHEN ("find_char_positions(e)") {

			auto ps = find_char_positions(dictionary, 'e');

			THEN ("expect {4, 9}") {

				REQUIRE(ps.value().size() == 2);
				REQUIRE(ps.value()[0] == 4);
				REQUIRE(ps.value()[1] == 9);
			}
		}
	}
}
