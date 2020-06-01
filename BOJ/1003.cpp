#include <iostream>
using namespace std;

#define N 45

//int cache[N][3];

/*
int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}
*/
int cache[N][2];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cache[0][0] = 1;
    cache[1][1] = 1;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            if (cache[i][0] != 0 || cache[i][1] != 0) continue;
            cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
            cache[i][1] = cache[i - 1][1] + cache[i - 2][1];
        }
        cout << cache[n][0] << " " << cache[n][1] << "\n";
    }

    return 0;
}