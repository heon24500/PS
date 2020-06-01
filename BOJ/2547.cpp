#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long N;
        cin >> N;

        long sum = 0;
        for (long j = 0; j < N; j++) {
            long candy;
            cin >> candy;
            sum += (candy % N);
        }

        if (sum % N == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}