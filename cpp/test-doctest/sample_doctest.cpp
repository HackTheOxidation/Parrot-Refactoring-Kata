#include "ApprovalTests.hpp"
#include "doctest/doctest.h"

#include <memory>

#include "Parrot.h"

using namespace std;
using namespace doctest;

TEST_CASE("Parrot") {

  SUBCASE("SpeedOfEuropeanParrot") {
    std::unique_ptr<Parrot> parrot = Parrot::create_parrot(ParrotType::EUROPEAN, 0, 0, false);
    CHECK(parrot->getSpeed() == Approx(12.0));
    CHECK(parrot->getCry() == "Sqoork!");
  }

  SUBCASE("SpeedOfAfricanParrot_With_One_Coconut") {
    auto parrot = Parrot::create_parrot(ParrotType::AFRICAN, 1, 0, false);
    CHECK(parrot->getSpeed() == Approx(3.0));
    CHECK(parrot->getCry() == "Squaark!");
  }

  SUBCASE("SpeedOfAfricanParrot_With_Two_Coconuts") {
    auto parrot = Parrot::create_parrot(ParrotType::AFRICAN, 2, 0, false);
    REQUIRE(parrot->getSpeed() == Approx(0.0));
  }

  SUBCASE("SpeedOfAfricanParrot_With_No_Coconuts") {
    auto parrot = Parrot::create_parrot(ParrotType::AFRICAN, 0, 0, false);
    REQUIRE(parrot->getSpeed() == Approx(12.0));
  }

  SUBCASE("SpeedNorwegianBlueParrot_nailed") {
    auto parrot = Parrot::create_parrot(ParrotType::NORWEGIAN_BLUE, 0, 0, true);
    CHECK(parrot->getSpeed() == Approx(0.0));
    CHECK(parrot->getCry() == "...");
  }

  SUBCASE("SpeedNorwegianBlueParrot_not_nailed") {
    auto parrot = Parrot::create_parrot(ParrotType::NORWEGIAN_BLUE, 0, 1.5, false);
    REQUIRE(parrot->getSpeed() == Approx(18.0));
  }

  SUBCASE("SpeedNorwegianBlueParrot_not_nailed_high_voltage") {
    auto parrot = Parrot::create_parrot(ParrotType::NORWEGIAN_BLUE, 0, 4, false);
    CHECK(parrot->getSpeed() == Approx(24.0));
    CHECK(parrot->getCry() == "Bzzzzzz");
  }
}
