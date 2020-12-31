
#include "day24.hpp"

int main()
{
    auto const print = [](auto const &e) { std::cout << e << '\n'; };
    auto const print_collection = [print](auto const &e) { std::ranges::for_each(e, print); };

    std::vector<location> tiles;

    for (auto const &line : read("input.txt"))
        tiles.push_back(string_to_directions(line));

    int count = 0;

    //

    for (auto &e : tiles)
    {
        auto const occurrences = std::count(tiles.begin(), tiles.end(), e);

        e.print();

        if (occurrences > 1)
        {
            //count++;
        }
    }

    std::cout << count << '\n';

    // 353 was wrong

    return 0;
}
