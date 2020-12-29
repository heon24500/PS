#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mat[101] = { 0 };
	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start; j < end; j++) mat[j]++;
	}
	for (int i = 1; i <= 100; i++) {
		if (mat[i] == 1) ans += a;
		else if (mat[i] == 2) ans += b * 2;
		else if (mat[i] == 3) ans += c * 3;
	}
	cout << ans;

	return 0;
}