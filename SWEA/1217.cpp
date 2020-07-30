/* 1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱 */
#include <iostream>
using namespace std;

int solve(int a, int b) {
	if (b == 0) return 1;
	return a * solve(a, b - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int t_num;
		cin >> t_num;

		int a, b;
		cin >> a >> b;
		int ret = solve(a, b);
		cout << "#" << t_num << " " << ret << '\n';
	}

	return 0;
}