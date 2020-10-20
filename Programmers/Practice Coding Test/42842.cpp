#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int total = brown + yellow;
    for (int m = 3; m <= total / 3; m++) {
        for (int n = 3; n <= m; n++) {
            if (n * m != total) continue;
            if ((n - 2) * (m - 2) == yellow) {
                answer.push_back(m);
                answer.push_back(n);
                return answer;
            }
        }
    }

    return answer;
}