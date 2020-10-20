#include <string>
#include <vector>

using namespace std;

int len, ans;
bool check[7], visited[10000000];

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve(int depth, string numbers, string s) {
    if (s != "" && !visited[stoi(s)]) {
        int num = stoi(s);
        visited[num] = true;
        if (isPrime(num)) ans++;
    }

    for (int i = 0; i < len; i++) {
        if (check[i]) continue;
        check[i] = true;
        solve(depth + 1, numbers, s + numbers[i]);
        check[i] = false;
    }
}

int solution(string numbers) {
    len = numbers.length();
    solve(0, numbers, "");

    return ans;
}