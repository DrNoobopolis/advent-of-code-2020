
#include "day24.hpp"

#include <set>

auto neutral_insert(std::set<location> &collection, location const &element) -> void
{
    auto const element_location = collection.find(element);
    bool const already_exists = element_location != collection.end();

    if (already_exists)
    {
        collection.erase(element_location);
    }
    else
    {
        collection.insert(element);
    }
}

int main()
{
    auto const print = [](auto const &e) { std::cout << e << '\n'; };
    auto const print_collection = [print](auto const &e) { std::for_each(e.begin(), e.end(), print); };

    std::set<location> tiles;

    for (auto const &line : read("input.txt"))
        neutral_insert(tiles, string_to_directions(line));

    // for (location const &e : tiles)
    // std::cout << e.string() << '\n';

    std::cout << tiles.size() << '\n';

    return 0;
}

// should use .h rather than .hpp

// go to definition using Ctrl + t

// commit button vscode
