/* 1208. [S/W 문제해결 기본] 1일차 - Flatten */
// 최대 높이는 -1, 최소 높이는 +1 과정을 덤프 횟수만큼 혹은 차이가 1 이하일때 까지 반복
// for와 if를 이용하거나 sort를 이용하여 최대, 최소값을 구하면 됨
#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int boxes[100];
		int dump = 0;
		cin >> dump;

		int max_height = 0, max_idx = -1;
		int min_height = 101, min_idx = -1;
		for (int i = 0; i < 100; i++) {
			cin >> boxes[i];
			if (max_height < boxes[i]) {
				max_height = boxes[i];
				max_idx = i;
			}
			if (min_height > boxes[i]) {
				min_height = boxes[i];
				min_idx = i;
			}
		}

		while (dump--) {
			boxes[max_idx]--;
			boxes[min_idx]++;

			max_height = 0, max_idx = -1;
			min_height = 101, min_idx = -1;
			for (int i = 0; i < 100; i++) {
				if (max_height < boxes[i]) {
					max_height = boxes[i];
					max_idx = i;
				}
				if (min_height > boxes[i]) {
					min_height = boxes[i];
					min_idx = i;
				}
			}

			if (max_height - min_height <= 1) break;
		}

		cout << "#" << t << " " << max_height - min_height << '\n';
	}

	return 0;
}