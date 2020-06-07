#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int> > q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
    }

    while (true) {
        answer++;
        int max = q.front().first;
        for (int i = 0; i < q.size(); i++) {
            pair<int, int> now = q.front();
            if (max < now.first) max = now.first;
            q.pop();
            q.push(now);
        }
        while (q.front().first != max) {
            pair<int, int> now = q.front();
            q.pop();
            q.push(now);
        }
        if (q.front().second == location) break;
        q.pop();
    }

    return answer;
}