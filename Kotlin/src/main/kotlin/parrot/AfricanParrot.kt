package parrot

import kotlin.math.max

class AfricanParrot(private val numberOfCoconuts: Int) : Parrot {
    override val speed: Double
        get() = max(0.0, baseSpeed - loadFactor * numberOfCoconuts)

    override val cry: String
        get() = "Sqaark!"

    private val loadFactor: Double
        get() = 9.0

}