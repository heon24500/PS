#include <iostream>
using namespace std;

int main() {
	int cnt[201] = { 0 };
	int n, v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cnt[num + 100]++;
	}
	cin >> v;
	cout << cnt[v + 100];

	return 0;
}