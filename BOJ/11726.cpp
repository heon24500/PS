#include <iostream>
using namespace std;

#define N 1005

int cache[N];

int Fill(int n) {
	if (n == 1) return cache[1] = 1;
	if (n == 2) return cache[2] = 2;
	if (cache[n]) return cache[n];
	return cache[n] = (Fill(n - 1) % 10007 + Fill(n - 2) % 10007) % 10007;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << Fill(n);

	return 0;
}