#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> h, a;
    for (int i = 0; i < N; i++) {
        int hi;
        cin >> hi;
        h.push_back(hi);
    }
    for (int i = 0; i < M; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    sort(h.begin(), h.end());
    sort(a.begin(), a.end());

    cout << h[h.size() - 1] + a[a.size() - 1];
}