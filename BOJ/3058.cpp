#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N[7], min = 100, sum = 0;

        for (int j = 0; j < 7; j++) {
            cin >> N[j];
            if (N[j] % 2 == 0) {
                sum += N[j];
                if (min > N[j]) min = N[j];
            }
        }

        cout << sum << " " << min << endl;
    }

    return 0;
}