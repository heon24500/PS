#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<string, string> mp;
	int n, m;
	cin >> n >> m;
	while (n--) {
		string key, value;
		cin >> key >> value;
		mp[key] = value;
	}
	while (m--) {
		string target;
		cin >> target;
		cout << mp[target] << "\n";
	}

	return 0;
}