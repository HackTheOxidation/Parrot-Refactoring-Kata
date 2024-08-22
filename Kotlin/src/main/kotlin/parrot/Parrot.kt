package parrot

interface Parrot {
    val speed: Double
    val cry: String

    val baseSpeed: Double
        get() = 12.0

    companion object {
        fun createParrot(type: ParrotTypeEnum, numberOfCoconuts: Int, voltage: Double, isNailed: Boolean): Parrot = when (type) {
            ParrotTypeEnum.EUROPEAN -> EuropeanParrot()
            ParrotTypeEnum.AFRICAN -> AfricanParrot(numberOfCoconuts)
            ParrotTypeEnum.NORWEGIAN_BLUE -> NorwegianBlueParrot(voltage, isNailed)
        }
    }
}
