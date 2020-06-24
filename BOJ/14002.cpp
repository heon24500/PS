#include <iostream>
using namespace std;

const int N = 1001;
int a[N], d[N], p[N];

void Print(int x) {
	if (x == -1) return;

	Print(p[x]);
	cout << a[x] << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int len = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		p[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
		
		if (len < d[i]) {
			len = d[i];
			ans = i;
		}
	}

	cout << len << '\n';
	Print(ans);

	return 0;
}