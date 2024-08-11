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

type parrotTraits struct {
	numberOfCoconuts int
	voltage          float64
	nailed           bool
}

func (parrot parrotTraits) loadFactor() float64 {
	return 9.0
}

func (parrot parrotTraits) baseSpeed() float64 {
	return 12.0
}

func (parrot parrotTraits) computeBaseSpeedForVoltage(voltage float64) float64 {
	return math.Min(24.0, voltage*parrot.baseSpeed())
}

type EuropeanParrot struct {
	parrotTraits
}

func (parrot EuropeanParrot) Speed() (float64, error) {
	return parrot.baseSpeed(), nil
}

func (parrot EuropeanParrot) Cry() (string, error) {
	return "Sqoork!", nil
}

type AfricanParrot struct {
	parrotTraits
}

func (parrot AfricanParrot) Speed() (float64, error) {
	return math.Max(0, parrot.baseSpeed()-parrot.loadFactor()*float64(parrot.numberOfCoconuts)), nil
}

func (parrot AfricanParrot) Cry() (string, error) {
	return "Sqaark!", nil
}

type NorwegianBlueParrot struct {
	parrotTraits
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
	traits := parrotTraits{numberOfCoconuts, voltage, nailed}
	switch t {
	case TypeEuropean:
		return EuropeanParrot{traits}, nil
	case TypeAfrican:
		return AfricanParrot{traits}, nil
	case TypeNorwegianBlue:
		return NorwegianBlueParrot{traits}, nil
	default:
		return nil, fmt.Errorf("Unknown parrot type passed")
	}
}
