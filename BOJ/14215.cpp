#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rec[3];
    for (int i = 0; i < 3; i++) {
        cin >> rec[i];
    }

    sort(rec, rec + 3);
    if (rec[0] + rec[1] <= rec[2]) rec[2] = rec[0] + rec[1] - 1;

    int sum = rec[0] + rec[1] + rec[2];
    cout << sum;
}