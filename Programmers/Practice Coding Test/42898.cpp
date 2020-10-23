#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 101, M = 101;
const ll mod = 1000000007;
ll dp[N][M];
bool check[N][M];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    dp[1][1] = 1;
    for (int i = 0; i < puddles.size(); i++) check[puddles[i][1]][puddles[i][0]] = true;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (check[y][x] || (y == 1 && x == 1)) continue;
            dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % mod;
        }
    }
    answer = dp[n][m];

    return answer;
}