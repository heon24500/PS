#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> timeline;
    int N, C, cnt = 0;
    cin >> N >> C;

    for (int i = 0; i < C; i++) {
        timeline.push_back(0);
    }

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        for (int i = 1; i <= C; i++) {
            if (i % t == 0 && timeline[i - 1] != 1) timeline[i - 1] = 1;
        }
    }

    for (int i = 0; i < C; i++) {
        cnt += timeline[i];
    }

    cout << cnt;
}