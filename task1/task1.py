# Python3 program to place tiles
import math

# Initialize variables
size_of_grid = 0
cnt = 0
arr = [[0 for i in range(128)] for j in range(128)]
colors = [1, 2, 3]  # Three colors for trominoes

def is_valid(x, y, color):
    # Check if the current position is valid for the color
    if x > 0 and arr[x-1][y] == color: return False
    if y > 0 and arr[x][y-1] == color: return False
    if x < size_of_grid-1 and arr[x+1][y] == color: return False
    if y < size_of_grid-1 and arr[x][y+1] == color: return False
    return True

def place(x1, y1, x2, y2, x3, y3):
    global cnt
    for color in colors:
        if is_valid(x1, y1, color) and is_valid(x2, y2, color) and is_valid(x3, y3, color):
            cnt += 1
            arr[x1][y1] = color
            arr[x2][y2] = color
            arr[x3][y3] = color
            return True
    return False

def tile(n, x, y, missing_x, missing_y):
    if n == 2:
        cnt = 1
        for i in range(n):
            for j in range(n):
                if (x+i, y+j) != (missing_x, missing_y):
                    arr[x + i][y + j] = cnt
        return True

    # Divide the grid into quadrants and tile them
    half = n // 2
    if not tile(half, x, y, missing_x, missing_y): return False
    if not tile(half, x, y + half, missing_x, missing_y): return False
    if not tile(half, x + half, y, missing_x, missing_y): return False
    if not tile(half, x + half, y + half, missing_x, missing_y): return False

    # Place the tromino at the center of the board
    mx, my = x + half - 1, y + half - 1
    if (mx, my) != (missing_x, missing_y):
        place(mx, my, mx, my+1, mx+1, my)

    return True

# Input and execution
n = int(input("Enter the value of n: "))
size_of_grid = int(math.pow(2, n))  # 2^n * 2^n board
missing_x, missing_y = map(int, input("Enter the coordinates of the missing square (x y): ").split())
arr[missing_x][missing_y] = 0  # Mark the missing square
if tile(size_of_grid, 0, 0, missing_x, missing_y):
    for i in range(size_of_grid):
        for j in range(size_of_grid):
            if arr[i][j] != 0:
                print(arr[i][j], end=" ")
            else:
                print("-", end=" ")  # Representing the missing square with "-"
        print()
else:
    print("Failed to tile the board with the given rules.")
