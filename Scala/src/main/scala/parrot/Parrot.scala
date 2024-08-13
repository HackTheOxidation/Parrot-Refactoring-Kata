package parrot

import parrot.ParrotType._

trait Parrot {
  def getSpeed: Double
  protected def getBaseSpeed: Double = 12.0
}

object Parrot {
  def createParrot(parrotType: ParrotType, numberOfCoconuts: Int, voltage: Double, isNailed: Boolean): Parrot = {
    parrotType match {
      case ParrotType.EUROPEAN => new EuropeanParrot
      case ParrotType.AFRICAN => new AfricanParrot(numberOfCoconuts)
      case ParrotType.NORWEGIAN_BLUE => new NorwegianBlueParrot(voltage, isNailed)
    }
  }
}
