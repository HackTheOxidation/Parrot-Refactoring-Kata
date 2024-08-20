#ifndef NORWEGIANBLUE_PARROT_HPP
#define NORWEGIANBLUE_PARROT_HPP

#include "Parrot.h"

#include <algorithm>

class NorwegianBlueParrot : public Parrot {
public:
  constexpr NorwegianBlueParrot(const double voltage, const bool isNailed)
      : voltage(voltage), isNailed(isNailed) {}

  const std::string_view getCry() const noexcept override {
    return (voltage > 0) ? "Bzzzzzz" : "...";
  }

  double getSpeed() const noexcept override {
    return (isNailed) ? 0 : getBaseSpeed(voltage);
  }

  ~NorwegianBlueParrot() = default;

private:
  const double voltage;
  const bool isNailed;

  constexpr double getBaseSpeed(double current_voltage) const noexcept {
    return std::min(24.0, current_voltage * Parrot::getBaseSpeed());
  }
};

#endif
