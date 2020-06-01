#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> h;
    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;
        h.push_back(height);
    }

    int max = h[0], cnt = 1;
    for (int i = 1; i < N; i++) {
        if (max < h[i]) {
            cnt++;
            max = h[i];
        }
    }

    cout << cnt << "\n";

    max = h[N - 1], cnt = 1;
    for (int i = N - 2; i >= 0; i--) {
        if (max < h[i]) {
            cnt++;
            max = h[i];
        }
    }

    cout << cnt;
}