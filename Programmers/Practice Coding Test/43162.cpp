#include <string>
#include <vector>
#include <queue>
using namespace std;

const int N = 205;
vector<int> adj[N];
queue<int> q;
bool visited[N];

void bfs(int x) {
    visited[x] = true;
    q.push(x);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            q.push(u);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (!computers[i][j]) continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    for (int i = 0; i < computers.size(); i++) {
        if (visited[i]) continue;
        bfs(i);
        answer++;
    }

    return answer;
}