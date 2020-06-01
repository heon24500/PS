#include <iostream>
#include <algorithm>
using namespace std;

#define N 20005

string str[N];

bool compare(string str1, string str2) {
	if (str1.length() != str2.length()) return str1.length() < str2.length();
	else return str1 < str2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str, str + n, compare);
	cout << str[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (str[i] != str[i - 1]) cout << str[i] << "\n";
	}

	return 0;
}