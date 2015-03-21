#include <iostream>

int main(void)
{
    char c;
    //unsigned int loss_counter = 0;
    //unsigned int loss_every = 100;

    while (std::cin.get(c)) {
        //loss_counter = (loss_counter + 1) % loss_every;
        //if (loss_counter == 0)
        //    c = -128;

        //std::cout << c;

        //std::cout << static_cast<unsigned>(s) << std::endl;

        //std::cout << i++ << ", " << std::hex << static_cast<unsigned>(s) << std::dec << std::endl;
        //std::cout << "Min, Max: [ " << min << " , " << max << " ]\n";

        //std::cout << "i: " << i << std::endl;

        std::cout << c;
    }

    return 0;
}
