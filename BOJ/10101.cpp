#include <iostream>
using namespace std;

int main() {
    int angle[3];
    int sum = 0;
    bool isEqual = true;

    for (int i = 0; i < 3; i++) {
        cin >> angle[i];
        sum += angle[i];

        if (angle[i] != 60) isEqual = false;
    }

    if (isEqual) cout << "Equilateral";
    else {
        if (sum == 180) {
            if ((angle[0] == angle[1]) || (angle[0] == angle[2]) || (angle[1] == angle[2])) cout << "Isosceles";
            else cout << "Scalene";
        }
        else cout << "Error";
    }

    return 0;
}