#include <iostream>
#include <cstdlib>
#define BOARD_SIZE 8

// Movement vectors for the knight
static int moveX[BOARD_SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
static int moveY[BOARD_SIZE] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Check if the position is within the chessboard
bool isWithinBoard(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

// Check if the chessboard cell is unvisited
bool isUnvisited(int board[], int x, int y) {
    return isWithinBoard(x, y) && (board[y * BOARD_SIZE + x] == -1);
}

// Get the number of unvisited cells adjacent to the current position
int getAdjacencyCount(int board[], int x, int y) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i)
        if (isUnvisited(board, x + moveX[i], y + moveY[i]))
            count++;
    return count;
}

// Select the next move based on Warnsdorff's heuristic
bool selectNextMove(int board[], int* x, int* y) {
    int minDegreeIndex = -1, degree, minDegree = BOARD_SIZE + 1, nextX, nextY;

    // Start from a random move and find the one with the minimum degree
    int start = rand() % BOARD_SIZE;
    for (int count = 0; count < BOARD_SIZE; ++count) {
        int index = (start + count) % BOARD_SIZE;
        nextX = *x + moveX[index];
        nextY = *y + moveY[index];
        if (isUnvisited(board, nextX, nextY) &&
            (degree = getAdjacencyCount(board, nextX, nextY)) < minDegree) {
            minDegreeIndex = index;
            minDegree = degree;
        }
    }

    // If no unvisited cell is found, return false
    if (minDegreeIndex == -1)
        return false;

    // Update the position to the selected move
    nextX = *x + moveX[minDegreeIndex];
    nextY = *y + moveY[minDegreeIndex];
    board[nextY * BOARD_SIZE + nextX] = board[(*y) * BOARD_SIZE + (*x)] + 1;
    *x = nextX;
    *y = nextY;

    return true;
}

// Display the chessboard with the knight's tour
void displayBoard(int board[]) {
    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x)
            std::cout << board[y * BOARD_SIZE + x] << '\t';
        std::cout << '\n';
    }
}

// Display the order of moves
void displayMoves(int board[]) {
    char moves[BOARD_SIZE * BOARD_SIZE][3];
    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            int move = board[y * BOARD_SIZE + x];
            moves[move - 1][0] = 'A' + x;
            moves[move - 1][1] = '1' + y;
            moves[move - 1][2] = '\0';
        }
    }
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        std::cout << moves[i];
        if (i < BOARD_SIZE * BOARD_SIZE - 1)
            std::cout << " -> ";
    }
    std::cout << '\n';
}

// Check if the knight's tour is closed
bool isTourClosed(int startX, int startY, int endX, int endY) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        if (startX + moveX[i] == endX && startY + moveY[i] == endY)
            return true;
    return false;
}

// Attempt to find a closed knight's tour using Warnsdorff's heuristic
bool findKnightTour() {
    int board[BOARD_SIZE * BOARD_SIZE];
    std::fill(board, board + BOARD_SIZE * BOARD_SIZE, -1);

    // Random starting position
    int startX = rand() % BOARD_SIZE;
    int startY = rand() % BOARD_SIZE;
    int x = startX, y = startY;
    board[y * BOARD_SIZE + x] = 1; // Mark the starting cell

    // Continue selecting next moves until the tour is complete
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE - 1; ++i)
        if (!selectNextMove(board, &x, &y))
            return false;

    // Check if the tour is closed
    if (!isTourClosed(startX, startY, x, y))
        return false;

    displayBoard(board);
    displayMoves(board);
    return true;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Keep trying until a closed tour is found
    while (!findKnightTour()) {}

    return 0;
}
