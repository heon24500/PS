#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		str += to_string(n);
		if (str.length() > m) break;
	}
	cout << str.substr(0, m);

	return 0;
}
