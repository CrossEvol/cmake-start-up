#include "hello.h"
#include "fmt/xchar.h"

int main() {
    Hello hello;
    hello.print();

    fmt::println("{}", "######");
    return 0;
}
