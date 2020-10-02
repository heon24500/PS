#include <iostream>
using namespace std;

const int N = 1000;
int n;
string num[N];

bool isExist(int idx) {
	for (int i = 0; i < n; i++) {
		string str1 = num[i].substr(idx);
		for (int j = i + 1; j < n; j++) {
			string str2 = num[j].substr(idx);
			if (str1 == str2) return true;
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int len = num[0].length();
	int ans = 0;
	for (int i = len - 1; i >= 0; i--) {
		ans++;
		if (!isExist(i)) break;
	}
	cout << ans;

	return 0;
}