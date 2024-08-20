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

  [[nodiscard]] virtual constexpr auto getSpeed() const noexcept -> double = 0;
  [[nodiscard]] virtual constexpr auto
  getCry() const noexcept -> std::string_view = 0;
  constexpr virtual ~Parrot() = default;

protected:
  constexpr Parrot() {};
  constexpr double getBaseSpeed() const noexcept { return 12.0; };
};

#endif // PARROT_PARROT_H
