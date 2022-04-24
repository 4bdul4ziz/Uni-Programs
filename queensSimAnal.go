package main

import (
	"flag"
	"fmt"
	"log"
	"math"
	"math/rand"
	"time"
)

// Permutation is a representation of state
type Permutation struct {
	length int
	state  []int
}

func (p *Permutation) init() {
	// generate initial placing
	p.state = make([]int, p.length)
	for i := 0; i < p.length; i++ {
		p.state[i] = i
	}

	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	r.Shuffle(len(p.state), func(i, j int) {
		p.state[i], p.state[j] = p.state[j], p.state[i]
	})
}

func (p *Permutation) energy() float64 {
	// attack count, check diagnal
	attack := 0

	dx := []int{1, 1, -1, -1}
	dy := []int{1, -1, 1, -1}

	for x := 0; x < p.length; x++ {
		y := p.state[x]

		for diff := 1; diff < p.length; diff++ {
			validMoveCount := 0
			for direction := 0; direction < 4; direction++ {
				xx := x + diff*dx[direction]
				yy := y + diff*dy[direction]

				if (0 <= xx && xx < p.length) && (0 <= yy && yy < p.length) {
					validMoveCount++

					if p.state[xx] == yy {
						attack++
					}
				}
			}

			if validMoveCount == 0 {
				break
			}
		}
	}

	return float64(attack)
}

func (p *Permutation) getNeighbour() Permutation {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))

	// swap two different positions
	p1 := 0
	p2 := 0

	for p1 == p2 {
		p1 = r.Int() % p.length
		p2 = r.Int() % p.length
	}

	newState := Permutation{length: p.length}
	newState.state = make([]int, p.length)
	copy(newState.state, p.state)
	newState.state[p1], newState.state[p2] = p.state[p2], p.state[p1]
	return newState
}

func (p *Permutation) print() {
	for i := 0; i < p.length; i++ {
		for j := 0; j < p.length; j++ {
			if p.state[i] == j {
				fmt.Printf("* ")
			} else {
				fmt.Printf(". ")
			}
		}
		fmt.Println("")
	}
	fmt.Println("Total attacks", p.energy())
}


func simulatedAnnealing(size, iteration int, mxTemp, mnTemp float64) Permutation {
	// init
	tempFactor := -math.Log(mxTemp / mnTemp)
	temperature := mxTemp
	log.Println("Initial temperature factor", tempFactor)

	// start
	candidate := Permutation{length: size}
	candidate.init()
	candidate.print()

	bestState := candidate
	for step := 1; step <= iteration; step++ {
		temperature = mxTemp * math.Exp(tempFactor*float64(step)/float64(iteration))

		neighbour := candidate.getNeighbour()

		dEnergy := neighbour.energy() - candidate.energy()
		if dEnergy > 0.0 && math.Exp(-dEnergy/temperature) < rand.Float64() {
			// don't move
		} else {
			// move
			candidate = neighbour

			// update
			if candidate.energy() < bestState.energy() {
				bestState = candidate
			}
		}
	}

	return bestState
}

func main() {
	// read argument
	size := flag.Int("size", 8, "The board size (n * n)")
	iterations := flag.Int("iteration", 1000, "The maximal iterations to run")
	mxTemp := flag.Float64("mxTemp", 100.0, "The max temperature to start with")
	mnTemp := flag.Float64("mnTemp", 1, "The min temperature to end with")
	flag.Parse()

	// run SA
	result := simulatedAnnealing(*size, *iterations, *mxTemp, *mnTemp)

	// Print result
	fmt.Println("Total attack count", result.energy())
	result.print()
}