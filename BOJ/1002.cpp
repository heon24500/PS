/* 1002. 터렛 */
/*
1. 원점의 좌표가 같을 경우
   1) 크기가 같을 경우 2) 크기가 다를 경우
2. 원점의 좌표가 다른 경우
   1) 원점 사이 거리 = 두 원의 크기의 합 -> 한점에서 만남
   2) 원점 사이 거리 > 두 원의 크기의 합 -> 두 원이 만나지 않음
   3) 원점 사이 거리 < 두 원의 크기의 합 -> 두 원이 겹침
      (1) 내접하는 경우 (2) 만나지 않는 경우 (3) 두 점에서 만나는 경우
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		double circle[2][3];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> circle[i][j];
			}
		}

		double dist = 0;
		for (int i = 0; i < 2; i++) {
			dist += (circle[0][i] - circle[1][i]) * (circle[0][i] - circle[1][i]);
		}
		dist = sqrt(dist);
		double r1 = circle[0][2]; // 큰 원
		double r2 = circle[1][2]; // 작은 원

		if (dist == 0) {
			// 원점의 좌표가 같은 경우
			if (r1 == r2) cout << "-1\n";
			else cout << "0\n";
		}
		else {
			// 원점의 좌표가 다른 경우
			if (dist == r1 + r2) cout << "1\n";
			else if (dist > r1 + r2) cout << "0\n";
			else {
				if (r1 < r2) swap(r1, r2);
				
				if (dist + r2 == r1) {
					// 내접하는 경우
					cout << "1\n";
				}
				else if (dist + r2 < r1) {
					// 만나지 않는 경우
					cout << "0\n";
				}
				else {
					// 두 점에서 만나는 경우
					cout << "2\n";
				}
			}
		}
	}

	return 0;
}