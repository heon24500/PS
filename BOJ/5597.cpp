#include <iostream>
using namespace std;

int students[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 28; i++) {
		int n;
		cin >> n;
		students[n] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (!students[i]) cout << i << "\n";
	}

	return 0;
}