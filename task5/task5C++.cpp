#include <iostream>
#include <vector>

// Function to print the moves
void printMoves(const std::vector<std::pair<int, int>>& moves) {
    for (const auto& move : moves) {
        std::cout << "Move coin from position " << move.first;
        std::cout << " to position " << move.second << std::endl;
    }
}

// Function to solve the coin pairing puzzle
void pairCoins(int n) {
    if (n % 4 != 0) {
        std::cout << "The puzzle cannot be solved for n = " << n << ". n must be a multiple of 4." << std::endl;
        return;
    }

    std::vector<int> coins(n, 1); // Initialize all positions with 1
    std::vector<std::pair<int, int>> moves;
    int jumpOver = 1; // Number of coins to jump over

    for (int move = 1; move <= n / 2; ++move) {
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 1) { // Find a coin that can jump
                int jumpDistance = 0; // Distance the coin will jump
                int j = i + 1; // Start checking the next position

                // Calculate the distance to jump based on the coins and pairs
                while (j < n && jumpDistance < jumpOver) {
                    jumpDistance += coins[j];
                    ++j;
                }

                // Check if the jump is valid
                if (j < n && coins[j] == 1) {
                    coins[i] = 0; // The initial position becomes empty
                    coins[j] = 2; // The destination becomes a pair
                    moves.push_back({ i, j }); // Record the move
                    break; // Move to the next jump
                }
            }
        }
        jumpOver++; // Increase the number of coins to jump over for the next move
    }

    // Check if all coins are paired
    bool allPaired = true;
    for (int coin : coins) {
        if (coin == 1) {
            allPaired = false;
            break;
        }
    }


    printMoves(moves);

}

int main() {
    int n = 12; // Number of coins
    pairCoins(n);
    return 0;
}