#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, idx = 0, now = 0;

    queue<pii> q;
    while (true) {
        answer++;
        if (!q.empty() && q.front().second + bridge_length == answer) {
            now -= q.front().first;
            q.pop();
        }
        if (idx < truck_weights.size() && (q.empty() || now + truck_weights[idx] <= weight)) {
            q.push({ truck_weights[idx], answer });
            now += truck_weights[idx];
            idx++;
        }
        if (idx == truck_weights.size() && q.empty()) break;
    }

    return answer;
}