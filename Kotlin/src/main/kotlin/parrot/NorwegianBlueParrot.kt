package parrot

import kotlin.math.min

class NorwegianBlueParrot(private val voltage: Double, private val isNailed: Boolean) : Parrot {
    override val speed: Double
        get() = if (isNailed) 0.0 else computeBaseSpeed

    override val cry: String
        get() = if (voltage > 0) "Bzzzzzz" else "..."

    private val computeBaseSpeed: Double = min(24.0, voltage * baseSpeed)
}