#ifndef EUROPEAN_PARROT_HPP
#define EUROPEAN_PARROT_HPP

#include "Parrot.h"
#include <string_view>

class EuropeanParrot : public Parrot {
public:
  EuropeanParrot() = default;
  double getSpeed() const noexcept override { return Parrot::getBaseSpeed(); };
  const std::string_view getCry() const noexcept override { return "Sqoork!"; };
  ~EuropeanParrot() = default;
};

#endif
