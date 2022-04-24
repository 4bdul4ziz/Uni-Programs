#program to demonstrate the tower of hanoi problem and visuallise it with ascii art

def ascii_art(board, board_size, board_color, board_width):
    #print the board
    print("\n")
    for i in range(board_size):
        for j in range(board_size):
            if board[i][j] == 0:
                print(" ", end="")
            else:
                print(board[i][j], end="")
        print("")
    print("\n")
def tower_of_hanoi_recursive(board, board_size, board_color, board_width, start, end, temp):
    #base case
    if start == end:
        return
    #recursive case
    else:
        #move the top disk from start to temp
        tower_of_hanoi_recursive(board, board_size, board_color, board_width, start, temp, end)
        #move the top disk from start to end
        board[start][end] = board[start][end] - 1
        ascii_art(board, board_size, board_color, board_width)
        #move the top disk from temp to end
        tower_of_hanoi_recursive(board, board_size, board_color, board_width, temp, end, start)

def tower_of_hanoi(board, board_size, board_color, board_width):
    #initialize the board
    board = [[0 for i in range(board_size)] for j in range(board_size)]
    #initialize the board with the number of disks
    for i in range(board_size):
        board[0][i] = board_size - i
    #print the board
    ascii_art(board, board_size, board_color, board_width)
    #call the recursive function
    tower_of_hanoi_recursive(board, board_size, board_color, board_width, 0, board_size - 1, board_size - 1)

def bestMoves(board, board_size, board_color, board_width):
    #initialize the board
    board = [[0 for i in range(board_size)] for j in range(board_size)]
    #initialize the board with the number of disks
    for i in range(board_size):
        board[0][i] = board_size - i
    #print the board
    ascii_art(board, board_size, board_color, board_width)
    #call the recursive function
    bestMoves_recursive(board, board_size, board_color, board_width, 0, board_size - 1, board_size - 1)

def main():
    #initialize the board
    board_size = int(input("Enter the size of the board: "))
    board_color = input("Enter the color of the board: ")
    board_width = int(input("Enter the width of the board: "))
    board = [[0 for i in range(board_size)] for j in range(board_size)]
    #initialize the board with the number of disks
    for i in range(board_size):
        board[0][i] = board_size - i
    #print the board
    ascii_art(board, board_size, board_color, board_width)
    #call the recursive function
    tower_of_hanoi(board, board_size, board_color, board_width)

    #initialize the board
    board_size = int(input("Enter the size of the board: "))
    board_color = input("Enter the color of the board: ")
    board_width = int(input("Enter the width of the board: "))
    board = [[0 for i in range(board_size)] for j in range(board_size)]
    #initialize the board with the number of disks
    for i in range(board_size):
        board[0][i] = board_size - i
    #print the board
    ascii_art(board, board_size, board_color, board_width)
    #call the recursive function
    bestMoves(board, board_size, board_color, board_width)

main()