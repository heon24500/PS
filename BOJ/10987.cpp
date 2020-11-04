#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ans++;
	}
	cout << ans;

	return 0;
}