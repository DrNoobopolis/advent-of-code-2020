#include <iostream>
#include <vector>
#include <fstream>

int accounting2(std::vector<int> const &vector)
{
    for (int x : vector)
        for (int y : vector)
            if (x + y == 2020)
                return x * y;

    return 0;
}

int accounting3(std::vector<int> const &vector)
{
    for (int x : vector)
        for (int y : vector)
            for (int z : vector)
                if (x + y + z == 2020)
                    return x * y * z;

    return 0;
}

void read(std::vector<int> &vector)
{
    std::ifstream read_file("input.txt");

    int integer;
    while (!read_file.eof())
    {
        read_file >> integer;
        vector.push_back(integer);
    }

    read_file.close();
}

/* 
has an error if text file has a space
should instead read a string -> integer
if read is blank/nan do not create a new entry
*/

int main()
{
    std::vector<int> expense_report;

    read(expense_report);

    std::cout << accounting2(expense_report) << '\n'; // part 1

    std::cout << accounting3(expense_report) << '\n'; // part 2

    return 0;
}
