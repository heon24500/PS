#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E, seconds = 0;
    cin >> A >> B >> C >> D >> E;

    bool flag = false;

    while (A < B) {
        if (A < 0) {
            flag = true;
            seconds += C;
            A++;
        }
        else if ((A == 0) && (flag == true)) {
            seconds += D;
            flag = false;
        }
        else {
            seconds += E;
            A++;
        }
    }

    cout << seconds;

    return 0;
}