#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> students(n + 1);
    for (int i = 0; i < lost.size(); i++) students[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++) students[reserve[i]]++;

    if (students[1] == 1 && students[2] == -1) {
        students[1]--;
        students[2]++;
    }
    for (int i = 2; i <= n - 1; i++) {
        if (students[i] < 1) continue;
        if (students[i - 1] == -1) {
            students[i - 1]++;
            students[i]--;
            continue;
        }
        if (students[i + 1] == -1) {
            students[i + 1]++;
            students[i]--;
            continue;
        }
    }
    if (students[n] == 1 && students[n - 1] == -1) {
        students[n]--;
        students[n - 1]++;
    }

    for (int i = 1; i <= n; i++) {
        if (students[i] != -1) answer++;
    }

    return answer;
}