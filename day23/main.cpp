/*
Before the crab starts, it will designate the first cup in your list as the current cup. The crab is then going to do 100 moves.

Each move, the crab does the following actions:

The crab picks up the three cups that are immediately clockwise of the current cup. 
They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
The crab selects a destination cup: the cup with a label equal to the current cup's label minus one. 
If this would select one of the cups that was just picked up, the crab will keep subtracting one until it finds a cup that wasn't just picked up. If at any point in this process the value goes below the lowest value on any cup's label, it wraps around to the highest value on any cup's label instead.
The crab places the cups it just picked up so that they are immediately clockwise of the destination cup. They keep the same order as when they were picked up.
The crab selects a new current cup: the cup which is immediately clockwise of the current cup.
For example, suppose your cup labeling were 389125467. If the crab were to do merely 10 moves, the following changes would occur:

-- move 1 --
cups: (3) 8  9  1  2  5  4  6  7 
pick up: 8, 9, 1
destination: 2

-- move 2 --
cups:  3 (2) 8  9  1  5  4  6  7 
pick up: 8, 9, 1
destination: 7

-- move 3 --
cups:  3  2 (5) 4  6  7  8  9  1 
pick up: 4, 6, 7
destination: 3

-- move 4 --
cups:  7  2  5 (8) 9  1  3  4  6 
pick up: 9, 1, 3
destination: 7

-- move 5 --
cups:  3  2  5  8 (4) 6  7  9  1 
pick up: 6, 7, 9
destination: 3

-- move 6 --
cups:  9  2  5  8  4 (1) 3  6  7 
pick up: 3, 6, 7
destination: 9

-- move 7 --
cups:  7  2  5  8  4  1 (9) 3  6 
pick up: 3, 6, 7
destination: 8

-- move 8 --
cups:  8  3  6  7  4  1  9 (2) 5 
pick up: 5, 8, 3
destination: 1

-- move 9 --
cups:  7  4  1  5  8  3  9  2 (6)
pick up: 7, 4, 1
destination: 5

-- move 10 --
cups: (5) 7  4  1  8  3  9  2  6 
pick up: 7, 4, 1
destination: 3

-- final --
cups:  5 (8) 3  7  4  1  9  2  6 

In the above example, the cups' values are the labels as they appear moving clockwise around the circle; the current cup is marked with ( ).

After the crab is done, what order will the cups be in? Starting after the cup labeled 1, collect the other cups' labels clockwise into a single string with no extra characters; each number except 1 should appear exactly once. In the above example, after 10 moves, the cups clockwise from 1 are labeled 9, 2, 6, 5, and so on, producing 92658374. If the crab were to complete all 100 moves, the order after cup 1 would be 67384529.

Using your labeling, simulate 100 moves. What are the labels on the cups after cup 1?

962713854.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ranges>

template <typename It>
auto next_rotate(It const &start, It const &finish, It const &current) -> It
{
    auto const next = std::next(current);

    if (next != finish)
        return next;
    else
        return start;
}

// iterator

template <typename It>
void move(It const &start, It const &finish, It const &current)
{
    std::rotate(current + 1, current + 4, finish);

    // std::for_each(start, finish - 3, [](auto const &e) { std::cout << e << '\n'; });

    int target = *current - 1;

    auto next = finish - 3;

    while (next == finish - 3)
    {
        next = std::find(start, finish - 3, target);
        target -= 1;

        std::cout << *next << '\n';
    }

    std::cout << *next << '\n';
}

int main()
{
    std::vector<int> cups = {3, 2, 5, 4, 6, 7, 8, 9, 1};

    // std::for_each(cups.begin(), cups.end() - 3, [](auto const &e) { std::cout << e << '\n'; });

    auto current = cups.begin() + 2;

    // std::cout << *current << '\n';

    // should be 3 not 4

    move(cups.begin(), cups.end(), current);

    /*
    cups: ( ) 8  9  1  2  5  4  6  7 
    pick up: 8, 9, 1
    destination: 2
    */

    /*
    auto next = cups.begin();

    for (int i = 0; i < 100; i++)
    {
        std::cout << *next << '\n';

        next = next_rotate(cups.begin(), cups.end(), next);
    }
    */

    return 0;
}