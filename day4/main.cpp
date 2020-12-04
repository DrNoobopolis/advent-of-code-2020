#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>
#include <sstream>

void read(std::vector<std::string> &string_passports)
{
    std::ifstream file("input.txt");

    std::string string_passport;

    while (!file.eof())
    {
        std::string line;

        std::getline(file, line);

        if (line == "")
        {
            string_passports.push_back(string_passport);
            string_passport = "";
        }
        else
        {
            string_passport += " " + line;
        }
    }

    string_passports.push_back(string_passport);

    file.close();
}

std::vector<std::string> split(std::string string_passport)
{
    std::vector<std::string> vector_passport;

    std::stringstream ss(string_passport);

    while (!ss.eof())
    {
        std::string temporary_string;
        ss >> temporary_string; // string
        //temporary_string = temporary_string.substr(0, 3); // 3 letters

        vector_passport.push_back(temporary_string);
    }

    return vector_passport;
}

// need to write better variable names

// WIP

bool valid(std::string string_passport)
{
    std::vector<std::string> const vector_passport = split(string_passport);

    int success = 0;

    /*
    byr - four digits 1920-2002
    iyr - four digits 2010-2020
    eyr - four digits 2020-2030
    hgt - number than cm (150-193) or in (59-76)
    hcl - "#" + six characters 0-9 or a-f
    ecl - {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"}
    pid - nine-digit including leading zeroes

    required fields and valid values

    how many passports are valid?
    */

    for (auto field : vector_passport)
    {
        std::string const field_name = field.substr(0, 3);

        std::cout << field_name << '\n';

        switch (field_name)
        {
        case "byr":
            //
            break;

        case "iyr":
            /* code */
            break;

        case "eyr":
            /* code */
            break;

        case "hgt":
            /* code */
            break;

        case "hcl":
            /* code */
            break;

        case "ecl":
            /* code */
            break;

        case "pid":
            /* code */
            break;

        default:
            break;
        }
    }

    return success == 7;
}

int main()
{
    std::vector<std::string> passports;

    read(passports); // error prone

    int valid_passports = 0;

    for (auto field : passports)
        if (valid(field))
            valid_passports++;

    std::cout << valid_passports << '\n';

    return 0;
}
