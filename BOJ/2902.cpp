#include <iostream>
using namespace std;

int main() {
	string str, ans;
	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') ans += str[i];
	}
	cout << ans;

	return 0;
}