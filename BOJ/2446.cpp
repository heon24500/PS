#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numStars = 2 * N + 1;
    int numBlanks = -1;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i < N) {
            numStars -= 2;
            numBlanks++;
        }
        else {
            numStars += 2;
            numBlanks--;
        }

        for (int j = 0; j < numBlanks; j++) {
            cout << " ";
        }

        for (int j = 0; j < numStars; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}