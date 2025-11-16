#include <iostream>


#include "twelve.h"


int main() {
    std::string str1;
    std::cin >> str1;
    std::string str2;
    std::cin >> str2;
    twelve::Twelve num1(str1);
    twelve::Twelve num2(str2);
    twelve::Twelve answer = twelve::Twelve::Add(num1, num2);
    answer.Print(std::cout);
    return 0;
}