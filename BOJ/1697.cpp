#include <iostream>
#include <queue>
using namespace std;

#define N 100005
#define K 100005

queue<int> q;
int dist[K];
bool visited[K];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    visited[n] = true;
    q.push(n);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        int tx[3];
        tx[0] = now - 1;
        tx[1] = now + 1;
        tx[2] = now * 2;

        for (int i = 0; i < 3; i++) {
            if (tx[i] >= 0 && tx[i] <= 100000 && !visited[tx[i]]) {
                visited[tx[i]] = true;
                q.push(tx[i]);
                dist[tx[i]] = dist[now] + 1;
            }
        }
    }

    cout << dist[k];
}