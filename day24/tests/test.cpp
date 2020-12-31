
#define CATCH_CONFIG_MAIN

// project
#include "day24.hpp"

// library
#include <catch2/catch.hpp>

TEST_CASE("Strings are split", "[split_string]")
{
    REQUIRE(string_to_directions("swseeneeswneenwneenwswenenwnewswnesw") == std::vector<std::string>{"two", "words"});
}
