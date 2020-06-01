#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define V 20005
#define E 300005
#define INF 1e9

vector<pii> adj[V];
priority_queue<pii> pq;
vector<int> dist(V, INF);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, k;
    cin >> v >> e;
    cin >> k;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    dist[k] = 0;
    pq.push(make_pair(0, k));

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

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}