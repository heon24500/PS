#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define INF 1e9
#define N 1005
#define M 100005

vector<pii> adj[N];
vector<int> dist(N, INF);
priority_queue<pii> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, src, dest;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    cin >> src >> dest;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    cout << dist[dest];

    return 0;
}