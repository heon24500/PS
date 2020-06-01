#include <iostream>
using namespace std;

int main() {
    int L, P, myPart;
    int part[5];

    cin >> L >> P;
    myPart = L * P;

    for (int i = 0; i < 5; i++) {
        cin >> part[i];
        cout << part[i] - myPart << " ";
    }

    return 0;
}