#include <catch2/catch_test_macros.hpp>
#include  "hello.h"
#define CATCH_CONFIG_MAIN


TEST_CASE("Echo returns input string", "[echo]") {
    Hello hello;
    REQUIRE(hello.echo("test") == "test");
    REQUIRE(hello.echo("hello world") == "hello world");
    REQUIRE(hello.echo("").empty());
}
