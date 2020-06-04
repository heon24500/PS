#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int su1[5] = { 1, 2, 3, 4, 5 };
int su2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int su3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        int ans = answers[i];
        if (ans == su1[i % 5]) cnt1++;
        if (ans == su2[i % 8]) cnt2++;
        if (ans == su3[i % 10]) cnt3++;
    }

    int maxi = max(cnt1, max(cnt2, cnt3));
    if (maxi == cnt1) answer.push_back(1);
    if (maxi == cnt2) answer.push_back(2);
    if (maxi == cnt3) answer.push_back(3);

    return answer;
}