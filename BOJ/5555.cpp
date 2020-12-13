#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string target;
	cin >> target;

	int n, cnt = 0;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		str += str;
		if (str.find(target) != string::npos) cnt++;
	}
	cout << cnt;

	return 0;
}