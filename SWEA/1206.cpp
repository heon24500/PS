/* 1206. [S/W 문제해결 기본] 1일차 - View */
// 어떤 기준 값 n. n-1 n-2 n+1 n+2 중 최대값을 찾아서 차이를 계속 더하면 됨
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int t_len;
		cin >> t_len;

		vector<int> buildings(t_len);
		for (int i = 0; i < t_len; i++) {
			cin >> buildings[i];
		}

		int ret = 0;
		for (int i = 2; i < t_len - 2; i++) {
			int max_height = max(max(buildings[i - 2], buildings[i - 1]), max(buildings[i + 1], buildings[i + 2]));
			if (buildings[i] > max_height) ret += buildings[i] - max_height;
		}

		cout << "#" << t << " " << ret << '\n';
	}

	return 0;
}