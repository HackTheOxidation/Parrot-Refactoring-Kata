package parrot

class AfricanParrot(numberOfCoconuts: Int) extends Parrot {
  override def getSpeed: Double = Math.max(0, getBaseSpeed - getLoadFactor * numberOfCoconuts)
  private def getLoadFactor: Double = 9.0
}
