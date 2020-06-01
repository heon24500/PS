#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N 1005
#define M 10005

vector<int> adj[N];
queue<int> q;
bool dfs_visited[N];
bool bfs_visited[N];

void dfs(int s) {
    if (dfs_visited[s]) return;
    dfs_visited[s] = true;

    cout << s << " ";

    for (auto u : adj[s]) {
        dfs(u);
    }
}

void bfs(int x) {
    bfs_visited[x] = true;
    q.push(x);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        cout << s << " ";

        for (auto u : adj[s]) {
            if (bfs_visited[u]) continue;
            bfs_visited[u] = true;
            q.push(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout << "\n";

    bfs(v);
}