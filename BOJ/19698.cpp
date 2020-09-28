#include <iostream>
using namespace std;

int main() {
	int n, w, h, l;
	cin >> n >> w >> h >> l;
	int max_n = (w / l) * (h / l);
	if (max_n < n) cout << max_n;
	else cout << n;

	return 0;
}