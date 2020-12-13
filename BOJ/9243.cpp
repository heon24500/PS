#include <iostream>
using namespace std;

bool solve(int n, string s1, string s2) {
	if (n == 0) {
		if (s1 == s2) return true;
		else return false;
	}
	else {
		for (int i = 0; s1[i]; i++) {
			if ((s1[i] == '1' && s2[i] == '1') || (s1[i] == '0' && s2[i] == '0')) return false;
		}
		return true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string src, dest;
	cin >> src >> dest;

	n %= 2;
	if (solve(n, src, dest)) cout << "Deletion succeeded";
	else cout << "Deletion failed";

	return 0;
}