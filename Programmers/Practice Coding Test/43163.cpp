#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool isPossible(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[i]) continue;
        cnt++;
        if (cnt > 1) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    map<string, int> dist, visited;

    int len = words.size();
    queue<string> q;
    q.push(begin);
    dist[begin] = 0;
    visited[begin] = 1;

    while (!q.empty()) {
        string now = q.front();
        q.pop();

        if (now == target) return dist[now];

        for (int i = 0; i < len; i++) {
            if (visited[words[i]] == 1) continue;
            if (!isPossible(now, words[i])) continue;
            q.push(words[i]);
            visited[words[i]] = 1;
            dist[words[i]] = dist[now] + 1;
        }
    }

    return answer;
}