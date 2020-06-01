#include <iostream>
using namespace std;

int main() {
    int N[7], min = 100, sum = 0;

    for (int i = 0; i < 7; i++) {
        cin >> N[i];

        if (N[i] % 2 != 0) {
            sum += N[i];

            if (min > N[i]) min = N[i];
        }
    }

    if (sum == 0) cout << -1;
    else cout << sum << endl << min;

    return 0;
}