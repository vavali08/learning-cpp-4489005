// Learning C++ 
// Challenge 01_03
// Console Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    std::string str;

    // std::flush ensures output is sent to terminal before user can enter input
    std::cout << "Enter your name: " << std::flush;

    // User input stored in str - only works for single words
    std::cin >> str;

    // prints back str to console
    std::cout << "Hello, " << str << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}
