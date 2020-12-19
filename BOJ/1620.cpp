#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, int> mp;
	vector<string> vect(n + 1);
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		vect[i] = str;
		mp[str] = i;
	}
	for (int i = 0; i < m; i++) {
		string target;
		cin >> target;
		if (target[0] >= '0' && target[0] <= '9') cout << vect[stoi(target)] << '\n';
		else cout << mp[target] << '\n';
	}

	return 0;
}