/* 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기 */
// 점수를 인덱스로 사용하여 입력 받을때 마다 해당 인덱스의 배열 값 +1 한 뒤 최대값 출력
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int t_num;
		cin >> t_num;

		int cnt[101];
		for (int i = 0; i <= 100; i++) {
			cnt[i] = 0;
		}

		int max_num = 0, ret = 0;
		for (int i = 0; i < 1000; i++) {
			int n;
			cin >> n;
			cnt[n]++;
			if ((max_num < cnt[n]) || (max_num == cnt[n] && ret < n)) {
				max_num = cnt[n];
				ret = n;
			}
		}

		cout << "#" << t_num << " " << ret << '\n';
	}

	return 0;
}