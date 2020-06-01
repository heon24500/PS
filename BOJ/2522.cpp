#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numStars = 1, numBlanks = N - 1;
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < numBlanks; j++) {
            cout << " ";
        }

        for (int j = 0; j < numStars; j++) {
            cout << "*";
        }

        if (i < N - 1) {
            numStars++;
            numBlanks--;
        }
        else {
            numStars--;
            numBlanks++;
        }

        cout << endl;
    }

    return 0;
}