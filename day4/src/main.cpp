
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include <charconv>
#include <ranges>

#include "expected.hpp"

auto read_passports(std::string const &filename) -> tl::expected<std::vector<std::string>, std::string>
{
    std::ifstream file(filename);

    if (file.good())
    {
        std::vector<std::string> collection;

        std::string record;

        for (std::string line; std::getline(file, line);)
        {
            if (line != "")
            {
                /* append fields from accross lines into an existing 
                   record */

                record += line + " ";
            }
            else if (record != "")
            {
                /* create a new record upon reading an empty line
                   do not create an empty record */

                collection.push_back(record);
                record = "";
            }
        }

        return collection;
    }
    else
    {
        /* ideally I would have liked to identify the particular 
           error e.g. file not found */

        return tl::make_unexpected("an error occured attempting to open the file");
    }
}

auto split_string(std::string const &string, char const delimiter = ' ') -> std::vector<std::string>
{
    std::vector<std::string> result;

    auto start = string.begin();
    auto finish = std::find(string.begin(), string.end(), delimiter);

    while (finish != string.end())
    {
        result.push_back({start, finish});

        start = std::next(finish);
        finish = std::find(start, string.end(), delimiter);
    }

    result.push_back({start, finish}); // finish = string.end()

    return result;
}

// needs to be refactored
auto valid(std::vector<std::string> const &passport_fields) -> bool
{
    int success = 0;

    for (auto passport : passport_fields)
    {
        std::string const field = passport.substr(0, 3); // error here

        std::string const data = passport.substr(4); // error here

        if (field == "byr")
        {
            int numeric_data = stoi(data);

            if (numeric_data >= 1920 && numeric_data <= 2002)
            {
                success++;
            }
        }

        if (field == "iyr")
        {
            int numeric_data = stoi(data);

            if (numeric_data >= 2010 && numeric_data <= 2020)
            {
                success++;
            }
        }

        if (field == "eyr")
        {
            int numeric_data = stoi(data);

            if (numeric_data >= 2020 && numeric_data <= 2030)
            {
                success++;
            }
        }

        if (field == "hgt")
        {
            std::string const unit = passport.substr(passport.size() - 2);

            std::string const value = passport.substr(4, passport.size() - 6);

            int result;

            std::from_chars(value.data(), value.data() + value.size(), result);

            if (unit == "cm" && 150 <= result && result <= 193)
            {
                success++;
            }

            if (unit == "in" && 59 <= result && result <= 76)
            {
                success++;
            }
        }

        if (field == "hcl")
        {
            int valid_characters = 0;

            // is there a count function in c++?

            for (int i = 1; i < data.size(); i++)
            {
                if ((data[i] >= '0' && data[i] <= '9') || (data[i] >= 'a' && data[i] <= 'f'))
                {
                    valid_characters++;
                }
            }

            if (data[0] == '#' && valid_characters == 6)
            {
                success++;
            }
        }

        if (field == "ecl")
        {
            std::vector<std::string> valid_strings = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

            bool found = valid_strings.end() != std::find(valid_strings.begin(), valid_strings.end(), data);

            if (found)
            {
                success++;
            }
        }

        if (field == "pid")
        {
            int valid_digits = 0;

            for (char const c : data)
            {
                if ('0' <= c && c <= '9')
                {
                    valid_digits++;
                }
            }

            if (valid_digits == 9)
            {
                success++;
            }
        }
    }

    return success == 7;
}
