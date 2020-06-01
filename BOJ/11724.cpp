#include <iostream>
#include <vector>
using namespace std;

#define N 1005
#define M 1000005

vector<int> adj[N];
bool visited[N];

void bfs(int s) {
    if (visited[s]) return;
    visited[s] = true;

    for (auto u : adj[s]) {
        bfs(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ret = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            ret++;
        }
    }

    cout << ret;
}