#include <gtest/gtest.h>
#include "hello.h"

TEST(HelloTest, EchoReturnsInputString) {
    Hello hello;
    EXPECT_EQ(hello.echo("test"), "test");
    EXPECT_EQ(hello.echo("hello world"), "hello world");
    EXPECT_TRUE(hello.echo("").empty());
}
