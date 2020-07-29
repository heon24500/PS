/* 1220. [S/W 문제해결 기본] 5일차 - Magnetic */
// 위 N극/아래 S극 자성체가 붙어있는 형상이 1개의 교착상태임
// 열을 중심으로 행을 검사하며 1, 2가 (사이 공백 가능) 연속되는 경우의 수를 count하여 출력
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int len;
		cin >> len;

		vector<vector<int> > table;
		for (int i = 0; i < len; i++) {
			vector<int> temp;
			for (int j = 0; j < len; j++) {
				int num;
				cin >> num;
				temp.push_back(num);
			}
			table.push_back(temp);
		}

		int ret = 0;
		for (int i = 0; i < 100; i++) {
			bool flag = false;
			for (int j = 0; j < 100; j++) {
				if (table[j][i] == 1) flag = true;
				if (table[j][i] == 2 && flag) {
					ret++;
					flag = false;
				}
			}
		}

		cout << "#" << t + 1 << " " << ret << '\n';
	}

	return 0;
}