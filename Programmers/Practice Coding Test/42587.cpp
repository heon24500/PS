#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pii> q;
    for (int i = 0; i < priorities.size(); i++) q.push({ priorities[i], i });
    while (true) {
        answer++;
        int max_p = 0;
        for (int i = 0; i < q.size(); i++) {
            int num = q.front().second;
            max_p = max(max_p, q.front().first);
            q.pop();
            q.push({ priorities[num], num });
        }

        while (q.front().first != max_p) {
            int num = q.front().second;
            q.pop();
            q.push({ priorities[num], num });
        }

        if (q.front().second == location) break;
        q.pop();
    }

    return answer;
}