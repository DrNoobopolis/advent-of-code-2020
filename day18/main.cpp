
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ranges>
#include <algorithm>
#include <memory>
#include <stdlib.h>

// read about exception handling

// simply report that an object was not created when accepting user input
// many types of errors and how to handel them

struct equation
{
    std::string value = "";

    equation(std::string input) // verify string is an equation
    {
        auto is_valid_char = [](char c) -> bool { return c == '(' || c == ')' || c == '*' || c == '+' || (c >= '0' && c <= '9'); };

        auto valid_chars = input | std::views::filter(is_valid_char); // remove invalid characters

        for (auto it = valid_chars.begin(); it != valid_chars.end(); it++) // repeated non_repeat characters
        {
            bool non_repeat = *it == '*' || *it == '+' || (*it >= '0' && *it <= '9');

            if (*it == *std::next(it) && non_repeat)
            {
                std::cerr << input << " : " << *it << " is repeated" << '\n';
                exit(EXIT_FAILURE);
            }
        }

        std::ranges::copy(valid_chars, std::back_inserter(this->value));
    }
};

struct node
{
    char value = 'z';
    node *left;
    node *right;
};

/*
how should this work?

build the tree up in reverse?

how would the tree work with brackets?

how can we collapse the tree?
just go down until left and right are 0-9 (digits)
*/

class tree
{
private:
    node traverse(std::string::iterator it)
    {
        node current;
        current.value = *it; // operator

        //current.left = ;

        if (*std::next(it) >= '0' && *std::next(it) <= '9')
        {
            current.left->value = *std::next(it);
        }
        else
        {
            std::cout << "whoa" << '\n';
            traverse(std::next(it, 2));
        }

        if (*std::next(it, -1) >= '0' && *std::next(it, -1) <= '9')
        {
            current.right->value = *std::next(it, -1);
        }
        else
        {
            std::cout << "bad" << '\n';
            //traverse(std::next(it, -2));
        }

        std::cout << current.right->value << '\n';

        return current;
    }

public:
    node build_tree(equation input)
    {
        std::string reverse;

        std::ranges::copy(input.value | std::views::reverse, std::back_inserter(reverse));

        node root = traverse(reverse.begin() + 1);

        //root.value = ;
        //root.right = it;
        //root.left = it;

        return root;
    }
};

// figuring out traverse is the difficult bit

int main()
{
    equation input("1 + 2 * 3 + 4 * 5 + 6");

    tree tree;

    node root = tree.build_tree(input);

    std::cout << root.left->value << '\n';

    return 0;
}
