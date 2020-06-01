#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numStars = 1;
    for (int i = 0; i < N; i++) {
        for (int j = N - i - 1; j > 0; j--) {
            cout << " ";
        }

        for (int j = 0; j < numStars; j++) {
            cout << "*";
        }

        numStars += 2;
        cout << endl;
    }

    return 0;
}