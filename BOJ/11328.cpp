#include <iostream>
using namespace std;

bool solve(string a, string b) {
	if (a.length() != b.length()) return false;

	int cnt[150] = { 0 };
	for (int i = 0; a[i]; i++) cnt[a[i]]++;
	for (int i = 0; b[i]; i++) cnt[b[i]]--;
	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt[i] != 0) return false;
	}

	return true;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string src, dest;
		cin >> src >> dest;
		if (solve(src, dest)) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}