#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> v;
	string str;
	cin >> str;

	int cnt[2] = { 0 };
	for (int i = 0; str[i]; i++) {
		cnt[str[i] - 'A']++;
	}
	if (cnt[0] > cnt[1]) cout << "A";
	else if (cnt[0] < cnt[1]) cout << "B";
	else cout << "Tie";

	return 0;
}