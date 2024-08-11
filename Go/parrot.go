package parrot

import (
	"fmt"
	"math"
)

type parrotType int

const (
	TypeEuropean      parrotType = 1
	TypeAfrican       parrotType = 2
	TypeNorwegianBlue parrotType = 3
)

// Parrot has a Speed and Cry.
type Parrot interface {
	Speed() (float64, error)
	Cry() (string, error)
}

func baseSpeed(parrot Parrot) float64 {
	return 12.0
}

type EuropeanParrot struct {
}

func (parrot EuropeanParrot) Speed() (float64, error) {
	return baseSpeed(parrot), nil
}

func (parrot EuropeanParrot) Cry() (string, error) {
	return "Sqoork!", nil
}

type AfricanParrot struct {
	numberOfCoconuts int
}

func (parrot AfricanParrot) loadFactor() float64 {
	return 9.0
}

func (parrot AfricanParrot) Speed() (float64, error) {
	coconutLoadFactor := parrot.loadFactor() * float64(parrot.numberOfCoconuts)
	return math.Max(0, baseSpeed(parrot)-coconutLoadFactor), nil
}

func (parrot AfricanParrot) Cry() (string, error) {
	return "Sqaark!", nil
}

type NorwegianBlueParrot struct {
	voltage float64
	nailed  bool
}

func (parrot NorwegianBlueParrot) computeBaseSpeedForVoltage(voltage float64) float64 {
	return math.Min(24.0, voltage*baseSpeed(parrot))
}

func (parrot NorwegianBlueParrot) Speed() (float64, error) {
	if parrot.nailed {
		return 0, nil
	} else {
		return parrot.computeBaseSpeedForVoltage(parrot.voltage), nil
	}
}

func (parrot NorwegianBlueParrot) Cry() (string, error) {
	if parrot.voltage > 0 {
		return "Bzzzzzz", nil
	} else {
		return "...", nil
	}
}

func CreateParrot(t parrotType, numberOfCoconuts int, voltage float64, nailed bool) (Parrot, error) {
	switch t {
	case TypeEuropean:
		return EuropeanParrot{}, nil
	case TypeAfrican:
		return AfricanParrot{numberOfCoconuts}, nil
	case TypeNorwegianBlue:
		return NorwegianBlueParrot{voltage, nailed}, nil
	default:
		return nil, fmt.Errorf("Unknown parrot type passed")
	}
}
