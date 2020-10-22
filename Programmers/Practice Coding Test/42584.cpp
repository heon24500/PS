#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> prices) {
    int n = prices.size();

    vector<int> answer(n);
    stack<pii> s;

    int i;
    for (i = 0; i < n; i++) {
        while (!s.empty() && s.top().first > prices[i]) {
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({ prices[i], i });
    }
    i--;

    while (!s.empty()) {
        answer[s.top().second] = i - s.top().second;
        s.pop();
    }

    return answer;
}