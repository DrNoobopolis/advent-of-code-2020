#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>

void read(std::vector<std::tuple<int, int, char, std::string>> &vector)
{
    std::ifstream read_file("input.txt");

    int lowest, highest;
    char key;
    std::string password;

    char remove;

    while (!read_file.eof())
    {
        read_file >> lowest;
        read_file >> remove;
        read_file >> highest;
        read_file >> key;
        read_file >> remove;
        read_file >> password;

        vector.push_back(std::make_tuple(lowest, highest, key, password));
    }

    read_file.close();
}

bool password_valid(std::tuple<int, int, char, std::string> e)
{
    int const lowest = std::get<0>(e);
    int const highest = std::get<1>(e);
    char const key = std::get<2>(e);
    std::string const password = std::get<3>(e);

    int const occurences = std::count(password.begin(), password.end(), key);

    if (occurences >= lowest && occurences <= highest)
    {
        return true;
    }

    return false;
}

bool password_valid2(std::tuple<int, int, char, std::string> e)
{
    int const first = std::get<0>(e) - 1;
    int const second = std::get<1>(e) - 1;
    char const key = std::get<2>(e);
    std::string const password = std::get<3>(e);

    // bool != bool (xor)

    if ((password[first] == key) != (password[second] == key))
    {
        return true;
    }

    return false;
}

int main()
{
    std::vector<std::tuple<int, int, char, std::string>> policy_passwords;

    read(policy_passwords);

    int valid_passwords = 0;

    for (auto e : policy_passwords)
        if (password_valid2(e))
            valid_passwords++;

    std::cout << valid_passwords << '\n';
}
