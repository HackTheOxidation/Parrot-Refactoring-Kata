#include <algorithm>
#include <stdexcept>
#include <string>

#include "AfricanParrot.hpp"
#include "EuropeanParrot.hpp"
#include "NorwegianBlueParrot.hpp"
#include "Parrot.h"

std::unique_ptr<Parrot> Parrot::create_parrot(ParrotType parrotType,
                                              int numberOfCoconuts,
                                              double voltage,
                                              bool isNailed) noexcept {
  switch (parrotType) {
  case ParrotType::EUROPEAN:
    return std::make_unique<EuropeanParrot>();
  case ParrotType::AFRICAN:
    return std::make_unique<AfricanParrot>(numberOfCoconuts);
  case ParrotType::NORWEGIAN_BLUE:
    return std::make_unique<NorwegianBlueParrot>(voltage, isNailed);
  }
}
