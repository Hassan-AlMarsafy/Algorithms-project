#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string hit_target(int n) {
    // Initialize the dp table
    vector<int> dp(n + 1, 0);

    // Base case: if n is 2, then two shots at the same spot solve the problem
    dp[2] = 2;

    // Fill the dp table
    for (int i = 3; i <= n; i++) {
        dp[i] = 2 * (i - 1) + 2;  // Add 2 for the extra shots at the second to last spot
    }

    // Initialize the shot counter
    int shot_counter = 0;

    // Initialize the target's position
    srand(time(0));
    int target_position = rand() % n + 1;

    // Sequence of shots for n > 2
    vector<int> shots;
    for (int i = 2; i < n; i++) {
        shots.push_back(i);
    }

    for (int i = n - 1; i > 1; i--) {
        shots.push_back(i);
    }

    for (int shot : shots) {
        cout << "Shooting at spot " << shot << ".\n";
        shot_counter += 1;
        string result;
        if (shot == target_position) {
            return "Target hit at spot " + to_string(shot) + " after " + to_string(shot_counter) + " shots!";
        }
        else {
            cout << "Target missed. Moving to the next spot.\n";
            // Move the target to an adjacent spot
            if (target_position > 1 && target_position < n) {
                target_position += rand() % 2 == 0 ? -1 : 1;
            }
            else if (target_position == 1) {
                target_position++;
            }
            else {
                target_position--;
            }
        }
    }

    return "Minimum shots needed to guarantee a hit: " + to_string(dp[n]);
}

int main() {
    int n;
    cout << "Enter number of spots\n";
    cin >> n;
    cout << hit_target(n);
    return 0;
}
