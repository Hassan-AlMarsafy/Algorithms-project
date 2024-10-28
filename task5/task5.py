import sys

# Function to print the moves
def print_moves(moves):
    for move in moves:
        print(f"Move coin from position {move[0]} to position {move[1]}")

# Function to solve the coin pairing puzzle
def pair_coins(n):
    if n % 4 != 0:
        print(f"The puzzle cannot be solved for n = {n}. n must be a multiple of 4.")
        return

    coins = [1] * n  # Initialize all positions with 1
    moves = []
    jump_over = 1  # Number of coins to jump over

    for move in range(1, n // 2 + 1):
        for i in range(n):
            if coins[i] == 1:  # Find a coin that can jump
                jump_distance = 0  # Distance the coin will jump
                j = i + 1  # Start checking the next position

                # Calculate the distance to jump based on the coins and pairs
                while j < n and jump_distance < jump_over:
                    jump_distance += coins[j]
                    j += 1

                # Check if the jump is valid
                if j < n and coins[j] == 1:
                    coins[i] = 0  # The initial position becomes empty
                    coins[j] = 2  # The destination becomes a pair
                    moves.append((i, j))  # Record the move
                    break  # Move to the next jump

        jump_over += 1  # Increase the number of coins to jump over for the next move

    # Check if all coins are paired
    all_paired = all(coin == 2 for coin in coins)

    print_moves(moves)

if __name__ == "__main__":
    n = 12  # Number of coins
    pair_coins(n)

