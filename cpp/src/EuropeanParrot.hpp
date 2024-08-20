#ifndef EUROPEAN_PARROT_HPP
#define EUROPEAN_PARROT_HPP

#include "Parrot.h"
#include <string_view>

class EuropeanParrot : public Parrot {
public:
  constexpr EuropeanParrot() = default;
  [[nodiscard]] constexpr double getSpeed() const noexcept override { return Parrot::getBaseSpeed(); };
  [[nodiscard]] constexpr std::string_view getCry() const noexcept override { return "Sqoork!"; };
};

#endif
