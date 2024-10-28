#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to calculate the minimum number of moves required
pair<int, vector<int>> minMoves(int n) {
    vector<int> dp(n + 1, INT_MAX);
    vector<vector<int>> moves(n + 1);

    // Base cases
    dp[0] = 0; // No switches, no moves needed
    dp[1] = 1; // Single switch requires 1 move (toggle rightmost)
    moves[1].push_back(1);

    // Fill dp and moves for each switch
    for (int i = 2; i <= n; ++i) {
        // To turn off switch i, we need to turn off all switches to the right first
        dp[i] = dp[i - 1] + i; // Initial assumption: toggle all previous switches and then switch i
        moves[i] = moves[i - 1];
        moves[i].push_back(i); // Toggle switch i

        for (int j = i - 1; j >= 1; --j) {
            // Toggle switch j to on, then toggle all switches to its right
            int currentMoves = dp[j] + (i - j) * 2;
            if (currentMoves < dp[i]) {
                dp[i] = currentMoves;
                moves[i] = moves[j];
                for (int k = j + 1; k <= i; ++k) {
                    moves[i].push_back(k); // Toggle switch k to off
                    moves[i].push_back(j); // Toggle switch j to on again
                }
            }
        }
    }

    return { dp[n], moves[n] };
}

int main() {
    int n;
    cout << "Enter the number of switches: ";
    cin >> n;

    pair<int, vector<int>> result = minMoves(n);
    cout << "Minimum number of moves required to turn off all switches: " << result.first << endl;
    cout << "The sequence of moves is: ";
    for (int move : result.second) {
        cout << "Toggle switch " << move << ", ";
    }
    cout << endl;

    return 0;
}
