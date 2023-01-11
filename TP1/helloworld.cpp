#include <iostream>
#include <string>

int main()
{
    std::string var;
    std::cout << "What's your name?" << std::endl;
    std::cin >> var;
    std::cout << "Hello " << var << "!" << std::endl;
    return 0;
}
