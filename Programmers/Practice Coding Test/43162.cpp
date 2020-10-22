#include <string>
#include <vector>
#include <queue>

using namespace std;

const int N = 200;
bool visited[N];
vector<int> adj[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || computers[i][j] == 0) continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        answer++;

        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (auto u : adj[now]) {
                if (visited[u]) continue;
                q.push(u);
                visited[u] = true;
            }
        }
    }

    return answer;
}