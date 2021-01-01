
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

// https://www.redblobgames.com/grids/hexagons/

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
    // axial coordinates

    int r = 0;
    int q = 0;

    auto string() const -> std::string
    {
        std::stringstream ss;

        ss << "r:" << this->r << " q:" << this->q;

        return ss.str();
    }

    auto operator<(location const &r) const -> bool
    {
        if (this->r != r.r)
            return this->r < r.r;

        return (this->q < r.q);
    }

    auto operator==(location const &r) const -> bool
    {
        return (this->r == r.r) && (this->q == r.q);
    }

    location(std::vector<std::string> const &directions)
    {
        int const NE = std::count(directions.begin(), directions.end(), "ne") - std::count(directions.begin(), directions.end(), "sw");
        int const E = std::count(directions.begin(), directions.end(), "e") - std::count(directions.begin(), directions.end(), "w");
        int const SE = std::count(directions.begin(), directions.end(), "se") - std::count(directions.begin(), directions.end(), "nw");

        this->r += E;

        this->r += NE;
        this->q -= NE;

        this->q += SE;
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

        if (std::find(expected.begin(), expected.end(), direction) != expected.end())
        {
            directions.push_back(direction);
            direction = "";
        }
    }

    // throw if direction != ""

    return directions;
}
// ignores space characters e.g. ' '
