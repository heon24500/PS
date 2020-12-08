#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string max_name, min_name;
	int max_bir[3], min_bir[3];

	string name;
	int birthday[3];
	cin >> name;
	max_name = min_name = name;
	for (int i = 0; i < 3; i++) {
		cin >> birthday[i];
		max_bir[i] = min_bir[i] = birthday[i];
	}

	for (int i = 1; i < n; i++) {
		cin >> name;
		for (int j = 0; j < 3; j++) cin >> birthday[j];

		for (int j = 2; j >= 0; j--) {
			if (max_bir[j] < birthday[j]) break;
			if (max_bir[j] > birthday[j]) {
				max_name = name;
				for (int j = 0; j < 3; j++) max_bir[j] = birthday[j];
			}
		}

		for (int j = 2; j >= 0; j--) {
			if (min_bir[j] > birthday[j]) break;
			if (min_bir[j] < birthday[j]) {
				min_name = name;
				for (int j = 0; j < 3; j++) min_bir[j] = birthday[j];
			}
		}
	}

	cout << min_name << '\n' << max_name << '\n';

	return 0;
}