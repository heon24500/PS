#include <iostream>
using namespace std;

int main() {
    int A[10], B[10], sumA = 0, sumB = 0;

    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) sumA += 3;
        else if (A[i] < B[i]) sumB += 3;
        else {
            sumA++;
            sumB++;
        }
    }

    cout << sumA << " " << sumB << endl;

    if (sumA > sumB) cout << "A";
    else if (sumA < sumB) cout << "B";
    else {
        bool isDraw = true;

        for (int i = 9; i >= 0; i--) {
            if (A[i] > B[i]) {
                cout << "A";
                isDraw = false;
                break;
            }
            if (A[i] < B[i]) {
                cout << "B";
                isDraw = false;
                break;
            }
        }

        if (isDraw) cout << "D";
    }

    return 0;
}