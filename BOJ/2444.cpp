#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numStars = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j < numStars; j++) {
            cout << "*";
        }

        numStars += 2;
        cout << endl;
    }

    numStars -= 4;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << " ";
        }

        for (int j = 0; j < numStars; j++) {
            cout << "*";
        }

        numStars -= 2;
        cout << endl;
    }

    return 0;
}