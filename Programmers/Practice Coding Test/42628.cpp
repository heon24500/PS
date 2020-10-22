#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> pq;
    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if (op == 'I') pq.push(num);
        if (op == 'D') {
            if (pq.empty()) continue;
            if (num == 1) pq.pop();
            else {
                queue<int> q;
                while (!pq.empty()) {
                    q.push(pq.top());
                    pq.pop();
                }
                while (q.size() > 1) {
                    pq.push(q.front());
                    q.pop();
                }
            }
        }
    }

    int min_num = 0, max_num = 0;
    if (!pq.empty()) max_num = pq.top();
    while (!pq.empty()) {
        min_num = pq.top();
        pq.pop();
    }

    answer.push_back(max_num);
    answer.push_back(min_num);
    return answer;
}