#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		map<string, int> m;
		int n;
		cin >> n;

		while (n--) {
			string clothes, temp;
			cin >> temp >> clothes;
			m[clothes]++;
		}

		int ans = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++) ans *= iter->second + 1;
		cout << ans - 1 << "\n";
	}


	return 0;
}