/* 1952. [모의 SW 역량테스트] 수영장 */
#include <iostream>
using namespace std;

int cost[4], days[12], day_cost[12][4];
int result[12];

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			day_cost[i][j] = 0;
		}
		result[i] = 0;
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> days[i];
			if (days[i] != 0) {
				day_cost[i][0] = days[i] * cost[0];
				day_cost[i][1] = cost[1];
				for (int j = i - 2; j <= i + 2; j++) {
					if (j < 0 || j > 11) continue;
					day_cost[j][2] = cost[2];
				}
			}
			day_cost[i][3] = cost[3];
		}
		// 1일권만 사용 시
		for (int i = 0; i < 12; i++) {
			if (i == 0) result[i] = day_cost[i][0];
			else result[i] = result[i - 1] + day_cost[i][0];
		}

		// 1일권 + 1개월권 사용 시
		for (int i = 0; i < 12; i++) {
			if (i == 0) result[i] = min(result[i], day_cost[i][1]);
			else result[i] = result[i - 1] + min(day_cost[i][0], day_cost[i][1]);
		}

		// 1일권 + 1개월권 + 3개월권 사용 시
		for (int i = 0; i < 12; i++) {
			if (i < 3) result[i] = min(result[i], day_cost[i][2]);
			else {
				result[i] = min(result[i - 3] + day_cost[i][2], result[i]);
				result[i] = min(result[i], result[i - 1] + min(day_cost[i][0], day_cost[i][1]));
			}
		}

		// 1일권 + 1개월권 + 3개월권 + 1년권 사용 시 
		result[11] = min(result[11], cost[3]);

		cout << "#" << tc << " " << result[11] << '\n';
		init();
	}

	return 0;
}