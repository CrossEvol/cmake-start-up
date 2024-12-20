#include "hello.h"
#include "fmt/xchar.h"

void Hello::print() {
    fmt::println("Hello World!");
}

std::string Hello::echo(std::string input) {
    return input;
}
