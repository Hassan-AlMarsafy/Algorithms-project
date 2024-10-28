
from collections import deque

# Define the board size and initial positions
BOARD_WIDTH = 4
BOARD_HEIGHT = 3
initial_white_positions = [(3, 0), (3, 1), (3, 2)]
initial_black_positions = [(0, 0), (0, 1), (0, 2)]

# Define the knight moves
knight_moves = [(2, 1), (1, 2), (-1, -2), (-2, -1), (-2, 1), (-1, 2), (1, -2), (2, -1)]

# Function to check if a move is within the board boundaries
def is_valid_position(position):
    x, y = position
    return 0 <= x < BOARD_WIDTH and 0 <= y < BOARD_HEIGHT

# Function to generate all possible moves for a knight
def generate_moves(start_position):
    x, y = start_position
    return [(x + dx, y + dy) for dx, dy in knight_moves if is_valid_position((x + dx, y + dy))]

# Function to check if the goal state is reached
def is_goal_state(white_positions, black_positions):
    return set(white_positions) == {(0, 0), (0, 1), (0, 2)} and set(black_positions) == {(3, 0), (3, 1), (3, 2)}

# BFS algorithm to find the minimum number of moves and the path taken
def bfs_min_moves(white_positions, black_positions):
    # Convert initial positions to tuples for hashing
    white_positions = tuple(white_positions)
    black_positions = tuple(black_positions)

    # Queue for BFS with initial state and path
    queue = deque([((white_positions, black_positions), 0, [])])
    visited = set()

    while queue:
        (white_positions, black_positions), moves, path = queue.popleft()
        if is_goal_state(white_positions, black_positions):
            return moves, path

        # Generate all possible moves for both white and black knights
        for positions, color in [(white_positions, 'W'), (black_positions, 'B')]:
            for i, knight_pos in enumerate(positions):
                for new_pos in generate_moves(knight_pos):
                    if new_pos not in white_positions and new_pos not in black_positions:
                        new_positions = list(positions)
                        new_positions[i] = new_pos
                        new_state = (tuple(new_positions), black_positions) if color == 'W' else (white_positions, tuple(new_positions))
                        if new_state not in visited:
                            visited.add(new_state)
                            new_path = path + [(color, knight_pos, new_pos)]
                            queue.append((new_state, moves + 1, new_path))

# Run the BFS algorithm
min_moves, path = bfs_min_moves(initial_white_positions, initial_black_positions)
print(f"The minimum number of moves required is: {min_moves}")
print("The moves are:")
for move in path:
    print(f"Move {move[0]} knight from {move[1]} to {move[2]}")
