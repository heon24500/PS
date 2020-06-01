#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int S1, S2, S3, num[81];
	cin >> S1 >> S2 >> S3;

	for (int i = 0; i <= S1 + S2 + S3; i++) {
		num[i] = 0;
	}


	for (int i = 1; i <= S1; i++) {
		for (int j = 1; j <= S2; j++) {
			for (int k = 1; k <= S3; k++) {
				num[i + j + k]++;
			}
		}
	}


	int max = 0, max_i = 0;
	for (int i = 0; i <= S1 + S2 + S3; i++) {
		if (max < num[i]) {
			max = num[i];
			max_i = i;
		}
	}

	cout << max_i;
}