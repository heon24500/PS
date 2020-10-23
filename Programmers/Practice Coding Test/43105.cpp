#include <string>
#include <vector>

using namespace std;

const int N = 500;
int dp[N][N];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();

    dp[0][0] = triangle[0][0];
    for (int i = 1; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (j == i) dp[i][j] = triangle[i][j] + dp[i - 1][i - 1];
            else dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    for (int i = 0; i < len; i++) answer = max(answer, dp[len - 1][i]);

    return answer;
}