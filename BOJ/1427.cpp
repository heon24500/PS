#include <iostream>
#include <algorithm>
using namespace std;

#define N 15

int num[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		num[i] = str[i] - '0';
	}

	sort(num, num + str.length());
	for (int i = str.length() - 1; i >= 0; i--) {
		cout << num[i];
	}

	return 0;
}