#include <iostream>

int main(void)
{
    char c;

    while (std::cin.get(c)) {
        if (c == '0')
            std::cout << "Sending:";
        std::cout << c;
    }

    return 0;
}
