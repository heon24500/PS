#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<pair<int, int> > bridge;
    int bridge_weight = 0;

    while (truck_weights.size() != 0 || !bridge.empty()) {
        if (!bridge.empty() && bridge.front().second + bridge_length == answer) {
            bridge_weight -= bridge.front().first;
            bridge.pop();
        }
        if (truck_weights.size() != 0 && bridge_weight + truck_weights[0] <= weight) {
            bridge_weight += truck_weights[0];
            bridge.push(make_pair(truck_weights[0], answer));
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
    }

    return answer;
}