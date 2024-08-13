package parrot

class NorwegianBlueParrot(voltage: Double, isNailed: Boolean) extends Parrot {
  override def getSpeed: Double = if (isNailed) 0 else getBaseSpeed(voltage)
  private def getBaseSpeed(voltage: Double): Double = Math.min(24.0, voltage * getBaseSpeed)
}
