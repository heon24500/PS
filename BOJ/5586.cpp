#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt[2] = { 0 };
	for (int i = 0; i < str.length() - 2; i++) {
		string s = str.substr(i, 3);
		if (s == "JOI") cnt[0]++;
		if (s == "IOI") cnt[1]++;
	}
	cout << cnt[0] << '\n' << cnt[1];

	return 0;
}