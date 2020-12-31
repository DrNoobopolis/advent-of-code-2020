
#include <vector>
#include <string>
#include <fstream>
#include <charconv>

#include <iostream>
#include <ranges>
#include <algorithm>
#include <array>
#include <sstream>

#include "../include/expected.hpp"

auto read(std::string const &filename) -> std::vector<std::string>
{
    std::ifstream file(filename);

    std::vector<std::string> collection;

    // if (file.good())
    // {
    for (std::string line; std::getline(file, line);)
        collection.push_back(line);
    // }

    return collection;
}

struct location
{
    int NE = 0; // SW
    int E = 0;  // W
    int SE = 0; // NW

    auto print() -> void
    {
        std::cout << "NE:" << this->NE << " E:" << this->E << " SE:" << this->SE << '\n';
    }

    auto operator<(location const &l) -> bool
    {
        return (this->NE < l.NE) && (this->E < l.E) && (this->SE < l.SE);
    }

    auto operator==(location const &l) -> bool
    {
        return (this->NE == l.NE) && (this->E == l.E) && (this->SE == l.SE);
    }

    location(std::vector<std::string> const &directions)
    {
        this->NE = std::ranges::count(directions, "ne") - std::ranges::count(directions, "sw");
        this->E = std::ranges::count(directions, "e") - std::ranges::count(directions, "w");
        this->SE = std::ranges::count(directions, "se") - std::ranges::count(directions, "nw");
    }
};

auto string_to_directions(std::string const &line) -> std::vector<std::string>
{
    std::stringstream ss(line);

    std::vector<std::string> directions;

    std::string direction;
    char character;

    std::vector<std::string> const expected = {"nw", "ne", "w", "e", "sw", "se"};

    while (ss >> character)
    {
        direction += character;

        if (std::ranges::find(expected, direction) != expected.end())
        {
            directions.push_back(direction);
            direction = "";
        }
    }

    // throw if direction != ""

    return directions;
}
// ignores space characters e.g. ' '

/*
            o
       NW       NE
    o               o
    
    W               E

    o               o
       SW       SE
            o
    
            o
        ooooooooo
    ooooooooooooooooo
    ooooooooooooooooo
    ooooooooooooooooo
    ooooooooooooooooo
    ooooooooooooooooo
        ooooooooo
            o
    
            o
        o       o
    o               o
    o               o
    o               o
    o               o
    o               o
        o       o
            o

            o
                 
    o               o
                     
                     
                     
    o               o
                 
            o
*/
