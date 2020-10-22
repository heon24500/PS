#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, v;

    int len = progresses.size(), idx = 0;
    for (int i = 0; i < len; i++) v.push_back(progresses[i]);
    while (true) {
        int b_idx = idx;
        for (int i = 0; i < len; i++) v[i] += speeds[i];
        while (idx < len && v[idx] >= 100) idx++;
        if (b_idx != idx) answer.push_back(idx - b_idx);
        if (idx == len) break;
    }

    return answer;
}