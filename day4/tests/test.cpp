
#define CATCH_CONFIG_MAIN

// project
#include "../src/day4.hpp"

// library
#include <catch2/catch.hpp>

TEST_CASE("Strings are split", "[split_string]")
{
    REQUIRE(split_string("two words") == std::vector<std::string>{"two", "words"});
    REQUIRE(split_string("single") == std::vector<std::string>{"single"});
    REQUIRE(split_string("a,b,c,d", ',') == std::vector<std::string>{"a", "b", "c", "d"});

    // undesirable
    REQUIRE(split_string("three words ") == std::vector<std::string>{"three", "words"});
    REQUIRE(split_string("   ") == std::vector<std::string>{});
    REQUIRE(split_string(" before") == std::vector<std::string>{"before"});
    REQUIRE(split_string("") == std::vector<std::string>{});
}

TEST_CASE("Substring", "[substr]")
{
    REQUIRE(std::string{"abcdef"}.substr(0, 3) == "abc");
}

TEST_CASE("Valid1", "[part 1]")
{
    REQUIRE(std::string{"abcdef"}.substr(0, 3) == "abc");

    // 192
}

TEST_CASE("Valid2", "[part 2]")
{
    REQUIRE(std::string{"abcdef"}.substr(0, 3) == "abc");
    REQUIRE(std::string{"a"}.substr(0, 3) == "a");

    // error
    // REQUIRE(std::string{"a"}.substr(4) == "a");

    // 101
}

// read_passports
// valid
