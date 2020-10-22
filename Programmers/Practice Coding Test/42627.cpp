#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 0; i < jobs.size(); i++) pq.push({ jobs[i][1], jobs[i][0] });
    while (true) {
        if (pq.empty()) break;
        queue<pii> q;
        while (!pq.empty() && pq.top().second > time) {
            q.push(pq.top());
            pq.pop();
        }
        if (pq.empty() || pq.top().second > time) time++;
        else {
            time += pq.top().first;
            answer += time - pq.top().second;
            pq.pop();
        }
        while (!q.empty()) {
            pq.push(q.front());
            q.pop();
        }
    }
    answer /= jobs.size();
    return answer;
}