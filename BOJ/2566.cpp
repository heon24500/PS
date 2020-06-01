#include <iostream>
using namespace std;

int main() {
    int N[9][9], max = 0, max_i = 0, max_j = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> N[i][j];
            if (max < N[i][j]) {
                max = N[i][j];
                max_i = i + 1;
                max_j = j + 1;
            }
        }
    }

    cout << max << endl;
    cout << max_i << " " << max_j;

    return 0;
}