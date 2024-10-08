#ifndef AFRICAN_PARROT_HPP
#define AFRICAN_PARROT_HPP

#include "Parrot.h"

class AfricanParrot : public Parrot {
public:
  constexpr AfricanParrot(int numberOfCoconuts)
      : numberOfCoconuts(numberOfCoconuts) {}

  [[nodiscard]] constexpr double getSpeed() const noexcept override {
    return std::max(0.0, Parrot::getBaseSpeed() -
                             getLoadFactor() * numberOfCoconuts);
  }

  [[nodiscard]] constexpr std::string_view getCry() const noexcept override {
    return "Squaark!";
  }

  constexpr ~AfricanParrot() = default;

private:
  int numberOfCoconuts;
  constexpr double getLoadFactor() const noexcept { return 9.0; };
};

#endif
