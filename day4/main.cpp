#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>
#include <sstream>

void read(std::vector<std::string> &passports)
{
    std::ifstream file("input.txt");

    std::string passport;

    while (!file.eof())
    {
        std::string line;

        std::getline(file, line);

        if (line == "")
        {
            passports.push_back(passport);
            passport = "";
        }
        else
        {
            passport += " " + line;
        }
    }

    file.close();
}

std::vector<std::string> split(std::string string_passport)
{
    std::vector<std::string> vector_passport;

    std::stringstream ss(string_passport);

    while (!ss.eof())
    {
        std::string temporary_string;
        ss >> temporary_string;                           // string
        temporary_string = temporary_string.substr(0, 3); // 3 letters

        vector_passport.push_back(temporary_string);
    }

    return vector_passport;
}

// need to write better variable names

// WIP

int main()
{
    std::unordered_set<std::string> expected_fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    std::string optional = "cid";

    std::vector<std::string> passports;

    read(passports);

    for (auto e : passports)
    {
        std::vector<std::string> const passport = split(e);

        int matching_fields = 0;

        for (auto i : passport)
        {
            if (expected_fields.find(i) != expected_fields.end())
            {
                matching_fields++;
            }
            else
            {
                if (i != optional)
                {
                    std::cout << "invalid" << '\n';
                }
            }
        }

        if (matching_fields == expected_fields.size())
        {
            std::cout << "valid" << '\n';
        }
        else
        {
            std::cout << "invalid" << '\n';
        }
    }

    return 0;
}
