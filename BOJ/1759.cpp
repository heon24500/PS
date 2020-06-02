#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(string str) {
	int mo = 0, ja = 0;
	for (char ch : str) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') mo++;
		else ja++;
	}

	if (mo >= 1 && ja >= 2) return true;
	else return false;
}

void solve(int n, vector<char> &a, string pwd, int idx) {
	if (pwd.length() == n) {
		if (check(pwd)) cout << pwd << '\n';
		return;
	}
	if (a.size() == idx) return;

	solve(n, a, pwd + a[idx], idx + 1);
	solve(n, a, pwd, idx + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, c;
	cin >> l >> c;
	
	vector<char> alpha(c);
	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());
	solve(l, alpha, "", 0);

	return 0;
}