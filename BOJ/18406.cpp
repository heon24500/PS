#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string n;
	cin >> n;

	int mid = n.length() / 2;
	int num1 = 0, num2 = 0;
	for (int i = 0; i < mid; i++) num1 += n[i] - '0';
	for (int i = mid; n[i]; i++) num2 += n[i] - '0';
	if (num1 == num2) cout << "LUCKY";
	else cout << "READY";

	return 0;
}