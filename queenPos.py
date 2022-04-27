from shutil import move
import time
import random
import math

class Board(object):
    def __init__(self, queens):
        self.queens = queens.copy()

    def __len__(self):
        return len(self.queens)
        
    def display(self):
        n = len(self.queens)
        for row in range(n):
            for column in range(n):
                if self.queens[column] == row:
                    print("Q", end=" ")
                else:
                    print(".", end=" ")
            print()

    def heuristic(self):
        """Compute the cost of this solution."""
        n = len(self.queens)
        cost = 0
        for column in range(n):
            for row in range(n):
                if self.queens[column] == row:
                    cost += 1
                else:
                    cost += abs(column - row)
        return cost
        
        h = 0
        ##checking columns
        for i in range(1, n):
            ##checking rows
            for j in range(i+1, n):
                if board[i] == board[j]:
                    h += 1
                x = j - i
                ##checking the diagonals
                if board[i] == board[j] - x or board[i] == board[j] + x:
                    h += 1
        return h
    
    def moves(self):
        """Return a list of possible moves given the current placements."""
        bestMoves = []
        optimalHeuristic = heuristic(board)
        for a, b in moves.iteritems():
            if b < optimalHeuristic:
                optimalHeuristic = b

        for a, b in moves.iteritems():
            if b == optimalHeuristic:
                bestMoves.append(a)

        return bestMoves


    def neighbor(self, move):
        """Return a Board instance like this one but with one move made."""
        bestMoves = []
        
        if len(bestMoves) > 0:
            
            pick = random.randint(0, len(bestMoves) - 1)
            column = bestMoves[pick][0]
            row = bestMoves[pick][1]
            board[column] = row
        return Board



class Agent(object):
    """Knows how to solve an n-queens problem with simulated annealing."""

    def anneal(self, board):
        """Return a list of moves to adjust queen placements."""
        temperature = len(board)**2
        annealRate = 0.95
        newHeuristic = board.heuristic()
        while temperature > 0.1:
            newBoard = board.neighbor(move)
            newHeuristic = newBoard.heuristic()
            if newHeuristic < board.heuristic():
            else:
                if math.exp(-(newHeuristic - board.heuristic()) / temperature) > random.random():
                    board = newBoard
            temperature *= annealRate
        return board.moves()


        while newHeuristic > 0:
            board = board.neighbor(move)
            newHeuristic = heuristic(board)
            newTemperature = max(temperature * annealRate, 0.01)
            temperature = newTemperature
            ##steps cap is here to avoid the algorithm getting stuck
            if steps >= 10000: 
                break

        boardCopy = list(board)
        foundMove = False

        while not foundMove:
            boardCopy = list(board)
            newRow = random.randint(0, len(board)-1)
            newColumn = random.randint(0, len(board)-1)
            boardCopy[newColumn] = newRow
            newHeuristic = heuristic(boardCopy)
            if newHeuristic < optimalHeuristic:
                foundMove = True
            else:
                delta_e = optimalHeuristic - newHeuristic
                ##aceptance prob equation min(1, e**(delta e/temp))
                acceptProbability = min(1, math.exp(delta_e/temperature))
                foundMove = random.random() <= acceptProbability
        return boardCopy

def main():
    print("Enter the number of queens")
    n = input()
    n=int(n)
    queens = dict()
    for column in range(n):
        row = random.choice(range(n))
        queens[column] = row

    board = Board(queens)
    board.display()

    agent = Agent()
    path = agent.anneal(board)

    while path:
        move = path.pop(0)
        board = board.neighbor(move)
        time.sleep(0.1)
        board.display()

if __name__ == '__main__':
    main()