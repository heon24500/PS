#include <string>
#include <vector>

using namespace std;

int ans[3][10] = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};
int cnt[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int max_cnt = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == ans[0][i % 5]) cnt[0]++;
        if (answers[i] == ans[1][i % 8]) cnt[1]++;
        if (answers[i] == ans[2][i % 10]) cnt[2]++;
    }

    for (int i = 0; i < 3; i++) max_cnt = max(max_cnt, cnt[i]);
    for (int i = 0; i < 3; i++) {
        if (max_cnt == cnt[i]) answer.push_back(i + 1);
    }

    return answer;
}