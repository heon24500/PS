#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int mini = 1000, maxi = 0;
	while (n--) {
		int score;
		cin >> score;
		maxi = max(maxi, score);
		mini = min(mini, score);
	}

	cout << maxi - mini;

	return 0;
}