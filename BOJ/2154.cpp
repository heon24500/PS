#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	for (int i = 1; i <= n; i++) str += to_string(i);
	cout << str.find(to_string(n)) + 1;

	return 0;
}