#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("LOW limit value test") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(42, 20, 30) == TOO_HIGH);
}
TEST_CASE("Normal value test") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
TEST_CASE("Same value test") {
  REQUIRE(inferBreach(20, 20, 20) == NORMAL);
}
TEST_CASE("F2_T1") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 37) == TOO_HIGH);
}
TEST_CASE("F2_T2") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 34) == NORMAL);
}
TEST_CASE("F2_T3") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -34) == TOO_LOW);
}

TEST_CASE("F2_T4") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 37) == TOO_HIGH);
}
TEST_CASE("F2_T5") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 34) == NORMAL);
}
TEST_CASE("F2_T6") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -34) == TOO_LOW);
}
TEST_CASE("F2_T7") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 37) == TOO_HIGH);
}
TEST_CASE("F2_T8") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 34) == NORMAL);
}
TEST_CASE("F2_T9") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -34) == TOO_LOW);
}

