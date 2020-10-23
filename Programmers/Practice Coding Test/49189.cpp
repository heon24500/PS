#include <string>
#include <vector>
#include <queue>

using namespace std;

const int N = 20001;
int max_dist = 0;
int dist[N];
bool visited[N];
vector<int> adj[N];

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        max_dist = max(max_dist, dist[now]);

        for (auto u : adj[now]) {
            if (visited[u]) continue;
            q.push(u);
            visited[u] = true;
            dist[u] = dist[now] + 1;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();
    for (int i = 2; i <= n; i++) {
        if (dist[i] == max_dist) answer++;
    }

    return answer;
}