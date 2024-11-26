/*
This program is to demonstrate the use of lambda functions in C++.
*/

#include <iostream>

int main()
{
    const int BUFFER = 10;
    auto lambda = [BUFFER](int value)
    {
        return value + BUFFER;
    };

    std::cout << lambda(10);
    return 0;
}
