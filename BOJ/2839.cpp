#include <iostream>
using namespace std;

int main() {
	int n, bag_5kg, bag_3kg;
	cin >> n;

	if (n >= 5) {
		// 5kg 이상인 경우
		if (n % 5 == 0) {
			// 5kg 봉지만으로 담을 수 있는 경우
			bag_5kg = n / 5;
			cout << bag_5kg << endl;
		}
		else {
			// 5kg 봉지만으로 담을 수 없는 경우
			int max_5kg = n / 5; // 5kg 봉지 최대 갯수

			// 5kg 봉지에 담을 수 있는지 확인
			for (bag_5kg = max_5kg; bag_5kg > 0; bag_5kg--) {
				int n2 = n - bag_5kg * 5;
				if (n2 % 3 == 0) {
					// 3kg 봉지로 남은 양을 담을 수 있는 경우
					bag_3kg = n2 / 3;
					cout << bag_5kg + bag_3kg << endl;
					return 0;
				}
				else {
					// 3kg 봉지로 남은 양을 담을 수 없는 경우
					continue;
				}
			}

			// 5kg 봉지에 담을 수 없는 경우
			if (n % 3 == 0) {
				// 3kg 봉지에 담을 수 있는 경우
				bag_3kg = n / 3;
				cout << bag_3kg << endl;
			}
			else {
				// 3kg 봉지에 담을 수 없는 경우
				cout << "-1" << endl;
			}
		}
	}
	else {
		// 5kg 미만인 경우
		if (n == 3) {
			cout << "1" << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}

	return 0;
}