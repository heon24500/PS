#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 105

vector<int> adj[N];
queue<int> q;
int dist[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, man1, man2;
    cin >> n;
    cin >> man1 >> man2;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    q.push(man1);
    visited[man1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto u : adj[now]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[now] + 1;
            q.push(u);
        }
    }

    if (dist[man2] == 0) cout << -1;
    else cout << dist[man2];
}