#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    char c;

    ofstream ofs;
    ofs.open ("/tmp/test.txt", std::ofstream::out);

    while (std::cin.get(c)) {
        //std::cout << c;
        ofs.put(c);
    }

    ofs.close();

    return 0;
}
