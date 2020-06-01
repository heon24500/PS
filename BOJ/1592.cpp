#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> ball;
    for (int i = 0; i < N; i++) {
        ball.push_back(0);
    }

    int index = 1, cnt = 0;
    ball[0] = 1;
    while (true) {
        cnt++;
        if (ball[index - 1] % 2 == 0) {
            index -= L;
            if (index <= 0) index += N;
        }
        else {
            index += L;
            if (index > N) index -= N;
        }
        ball[index - 1]++;
        if (ball[index - 1] == M) break;
    }

    cout << cnt;
}