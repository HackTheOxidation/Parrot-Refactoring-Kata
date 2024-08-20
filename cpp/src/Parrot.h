#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

#include <memory>
#include <string_view>

enum class ParrotType { EUROPEAN, AFRICAN, NORWEGIAN_BLUE };

class Parrot {
public:
  static std::unique_ptr<Parrot> create_parrot(ParrotType parrotType,
                                               int numberOfCoconuts,
                                               double voltage,
                                               bool isNailed) noexcept;

  virtual double getSpeed() const noexcept = 0;
  virtual const std::string_view getCry() const noexcept = 0;

protected:
  constexpr Parrot() {};
  constexpr double getBaseSpeed() const noexcept { return 12.0; };
};

#endif // PARROT_PARROT_H
