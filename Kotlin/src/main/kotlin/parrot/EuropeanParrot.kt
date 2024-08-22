package parrot

class EuropeanParrot() : Parrot {
    override val speed: Double
        get() = baseSpeed

    override val cry: String
        get() = "Sqoork!"
}
