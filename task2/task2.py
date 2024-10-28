import random

BOARD_SIZE = 8
move_x = [2, 1, -1, -2, -2, -1, 1, 2]
move_y = [1, 2, 2, 1, -1, -2, -2, -1]

def is_within_board(x, y):
    return (x >= 0 and x < BOARD_SIZE and y >= 0 and y < BOARD_SIZE)

def is_unvisited(board, x, y):
    return is_within_board(x, y) and (board[y][x] == -1)

def get_adjacency_count(board, x, y):
    count = 0
    for i in range(BOARD_SIZE):
        if is_unvisited(board, x + move_x[i], y + move_y[i]):
            count += 1
    return count

def select_next_move(board, x, y):
    min_degree_index = -1
    min_degree = BOARD_SIZE + 1
    start = random.randint(0, BOARD_SIZE - 1)
    for count in range(BOARD_SIZE):
        index = (start + count) % BOARD_SIZE
        next_x = x + move_x[index]
        next_y = y + move_y[index]
        if is_unvisited(board, next_x, next_y):
            degree = get_adjacency_count(board, next_x, next_y)
            if degree < min_degree:
                min_degree_index = index
                min_degree = degree
    if min_degree_index == -1:
        return False
    next_x = x + move_x[min_degree_index]
    next_y = y + move_y[min_degree_index]
    board[next_y][next_x] = board[y][x] + 1
    return next_x, next_y

def display_board(board):
    for row in board:
        print('\t'.join(str(cell) for cell in row))
        print()

def is_tour_closed(start_x, start_y, end_x, end_y):
    for i in range(BOARD_SIZE):
        if start_x + move_x[i] == end_x and start_y + move_y[i] == end_y:
            return True
    return False

def find_knight_tour():
    board = [[-1 for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]
    start_x = random.randint(0, BOARD_SIZE - 1)
    start_y = random.randint(0, BOARD_SIZE - 1)
    x, y = start_x, start_y
    board[y][x] = 1
    for _ in range(BOARD_SIZE * BOARD_SIZE - 1):
        result = select_next_move(board, x, y)
        if not result:
            return False
        x, y = result
    if not is_tour_closed(start_x, start_y, x, y):
        return False
    display_board(board)
    return True

if __name__ == "__main__":
    while not find_knight_tour():
        pass
