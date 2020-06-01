#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numStars = 1;
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < numStars; j++) {
            cout << "*";
        }

        if (i < N - 1) numStars++;
        else numStars--;

        cout << endl;
    }

    return 0;
}