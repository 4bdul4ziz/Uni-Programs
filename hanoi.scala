object Hanoi {

  type DiskId = Int
  type TowerId = String
  type Tower = (TowerId, List[DiskId])
  case class Towers(source: Tower, destination: Tower, aux: Tower)

  def hanoi(numDisks: Int, source: Tower, destination: Tower, aux: Tower): (Tower, Tower, Tower) =
    if (numDisks == 1) {
      println(s"Move ${source._1} to ${destination._1}")
      (
        (source._1, source._2.tail),
        (destination._1, source._2.head :: destination._2),
        aux
      )}
    else {
      val (s1, a1, d1) = hanoi(numDisks - 1, source, aux, destination)
      val (s2, d2, a2) = hanoi(1, s1, d1, a1)
      val (a3, d3, s3) = hanoi(numDisks - 1, a2, d2, s2)
      (s3, d3, a3)
  }

  def main(args: Array[String]): Unit = {
    println(hanoi(5, ("A", (1 to 15).toList), ("B", List()), ("C", List())))
  }
}