#include <iostream>
#include <vector>
using namespace std;

bool isPerfect;

vector<int> divisor(int n) {
	vector<int> ret;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			sum += i;
		}
	}
	if (sum == n) isPerfect = true;
	else isPerfect = false;

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n, sum = 0;
		cin >> n;
		if (n == -1) break;
		vector<int> div = divisor(n);
		if (isPerfect) {
			cout << n << " = ";
			for (int i = 0; i < div.size(); i++) {
				if (i != 0) cout << " + ";
				cout << div[i];
			}
			cout << '\n';
		}
		else cout << n << " is NOT perfect.\n";
	}

	return 0;
}