from abc import abstractmethod
from enum import Enum


class ParrotType(Enum):
    EUROPEAN = 1
    AFRICAN = 2
    NORWEGIAN_BLUE = 3


class Parrot:

    @staticmethod
    def create_parrot(
        type_of_parrot: ParrotType,
        number_of_coconuts: int,
        voltage: float,
        nailed: bool,
    ):
        match type_of_parrot:
            case ParrotType.EUROPEAN:
                return EuropeanParrot()
            case ParrotType.AFRICAN:
                return AfricanParrot(number_of_coconuts)
            case ParrotType.NORWEGIAN_BLUE:
                return NorwegianBlueParrot(voltage, nailed)

    @property
    @abstractmethod
    def type(self) -> ParrotType:
        pass

    @abstractmethod
    def speed(self) -> float:
        pass

    @abstractmethod
    def cry(self) -> str:
        pass

    def _base_speed(self):
        return 12.0


class EuropeanParrot(Parrot):

    @property
    def type(self) -> ParrotType:
        return ParrotType.EUROPEAN

    def speed(self) -> float:
        return self._base_speed()

    def cry(self) -> str:
        return "Sqoork!"


class AfricanParrot(Parrot):

    def __init__(self, number_of_coconuts: int):
        self._number_of_coconuts = number_of_coconuts

    @property
    def type(self) -> ParrotType:
        return ParrotType.AFRICAN

    def speed(self) -> float:
        coconut_factor = self._load_factor() * self._number_of_coconuts
        return max(0, self._base_speed() - coconut_factor)

    def _load_factor(self):
        return 9.0

    def cry(self) -> str:
        return "Sqaark!"


class NorwegianBlueParrot(Parrot):
    def __init__(self, voltage: float, nailed: bool):
        self._voltage = voltage
        self._nailed = nailed

    def _compute_base_speed_for_voltage(self):
        return min(24.0, self._voltage * self._base_speed())

    def speed(self) -> float:
        return 0 if self._nailed else self._compute_base_speed_for_voltage()

    def cry(self) -> str:
        return "Bzzzzzz" if self._voltage > 0 else "..."
