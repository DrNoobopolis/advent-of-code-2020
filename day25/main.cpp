
#include <iostream>

auto transform(int const &subject, int const &N) -> int
{
    long value = 1;

    for (int i = 0; i < N; i++)
    {
        value *= subject; // can overflow if value is an int
        value %= 20201227;
    }

    return value;
}

auto transform_until(int const &subject, int const &expected) -> int
{
    int value = 1;

    int N = 0;

    while (value != expected)
    {
        value *= subject;
        value %= 20201227;

        N++;
    }

    return N;
}

void brute2(int const &card_public_key, int const &door_public_key)
{
    int card_secret_loop_size = transform_until(7, card_public_key);
    int door_secret_loop_size = transform_until(7, door_public_key);

    int encryption_key1 = transform(door_public_key, card_secret_loop_size);
    int encryption_key2 = transform(card_public_key, door_secret_loop_size);

    // they should be equal
    std::cout << encryption_key1 << '\n';
    std::cout << encryption_key2 << '\n';
}

int main()
{
    brute2(19452773, 12232269); // actual

    return 0;
}
