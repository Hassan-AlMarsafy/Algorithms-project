#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

int find_fake_box() {
    int real_weight = 10;  // weight of a real piece of metal
    int fake_weight = 9;  // weight of a fake piece of metal
    vector<vector<int>> boxes(50, vector<int>(50, real_weight));  // all boxes initially have real pieces

    srand(time(0));  // seed for random number generator
    int fake_box = rand() % 50;  // randomly select a box to contain fake pieces
    fill(boxes[fake_box].begin(), boxes[fake_box].end(), fake_weight);  // replace real pieces with fake pieces in the selected box

    int expected_weight = (50 * 51 / 2) * real_weight;  // assuming all pieces are real
    int actual_weight = 0;  // total weight of pieces
    for (int i = 1; i <= 50; ++i) {
        actual_weight += i * boxes[i - 1][0];
    }

    return expected_weight - actual_weight;  // box number with fake pieces
}

int main() {
    // Test the function
    cout << "The fake box is number: " << find_fake_box() << endl;  // outputs: the number of the box with fake pieces

    return 0;
}
