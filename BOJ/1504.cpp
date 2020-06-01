#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define INF 1e9
#define N 805
#define E 100005

vector<pii> adj[N];

vector<int> dijk(int src) {
    vector<int> dist(N, INF);
    priority_queue<pii> pq;

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

    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, e, v1, v2;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;

    vector<int> dist_src = dijk(1);
    vector<int> dist_v1 = dijk(v1);
    vector<int> dist_v2 = dijk(v2);

    /*
    int ret12 = dist_src[v1] + dist_v1[v2] + dist_v2[n];  // 1 -> v1 -> v2 -> N
    int ret21 = dist_src[v2] + dist_v2[v1] + dist_v1[n];  // 1 -> v2 -> v1 -> N
    int ret = min(ret12, ret21);
    if (ret == INF) cout << "-1";
    else cout << ret;
    */
    if (dist_src[v1] == INF || dist_v1[v2] == INF || dist_v2[n] == INF) {
        if (dist_src[v2] != INF && dist_v2[v1] != INF && dist_v1[n] != INF) cout << dist_src[v2] + dist_v2[v1] + dist_v1[n];
        else cout << "-1";
    }
    else if (dist_src[v2] == INF || dist_v2[v1] == INF || dist_v1[n] == INF) cout << dist_src[v1] + dist_v1[v2] + dist_v2[n];
    else cout << min(dist_src[v1] + dist_v1[v2] + dist_v2[n], dist_src[v2] + dist_v2[v1] + dist_v1[n]);

    return 0;
}