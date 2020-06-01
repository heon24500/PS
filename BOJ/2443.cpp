#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numStars = 2 * N - 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = numStars; j > 0; j--) {
            cout << "*";
        }

        numStars -= 2;
        cout << endl;
    }

    return 0;
}