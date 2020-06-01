#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int pointAtoD[4], pointEtoF[2];
    for (int i = 0; i < 4; i++) {
        cin >> pointAtoD[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> pointEtoF[i];
    }

    sort(pointAtoD, pointAtoD + 4);
    sort(pointEtoF, pointEtoF + 2);

    int result = pointAtoD[1] + pointAtoD[2] + pointAtoD[3] + pointEtoF[1];
    cout << result;

    return 0;
}