#include <iostream>

#include "hello.h"
#include "fmt/xchar.h"

int main() {
    Hello hello;
    hello.print();

    fmt::println("{}", "######");

#if defined(__clang__)
    std::cout << "You are using Clang." << std::endl;
#elif defined(__GNUC__) || defined(__GNUG__)
    std::cout << "You are using GCC." << std::endl;
#elif defined(_MSC_VER)
    std::cout << "You are using MSVC." << std::endl;
#else
    std::cout << "Unknown compiler." << std::endl;
#endif

    return 0;
}
