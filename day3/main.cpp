#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>

void read(std::vector<std::string> &vector)
{
    std::ifstream read_file("input.txt");

    std::string line;

    while (!read_file.eof())
    {
        read_file >> line;

        vector.push_back(line);
    }

    read_file.close();
}

int path(std::vector<std::string> const &mountain, std::pair<int, int> const &approach)
{
    int right = 0;
    int collisions = 0;

    for (int down = 0; down < mountain.size(); down += approach.second) // down
    {
        if (mountain[down][right] == '#')
            collisions++;

        right = (right + approach.first) % mountain[0].size(); // right
    }

    return collisions;
}

int main()
{
    std::vector<std::string> mountain;

    read(mountain);

    // part 1
    std::cout << path(mountain, std::make_pair(3, 1)) << '\n';

    std::vector<std::pair<int, int>> approaches = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

    // part 2

    int answer = 1;

    for (auto e : approaches)
        answer *= path(mountain, e);

    std::cout << answer << '\n';

    return 0;
}
