#include <iostream>
using namespace std;

int main() {
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	int d = 0;
	int width = t % (w * 2);
	int height = t % (h * 2);
	while (width > 0) {
		if (p == w) d = 1;
		if (p == 0) d = 0;
		if (d == 0) p++;
		else p--;
		width--;
	}
	d = 0;
	while (height > 0) {
		if (q == h) d = 1;
		if (q == 0) d = 0;
		if (d == 0) q++;
		else q--;
		height--;
	}
	cout << p << ' ' << q << '\n';


	return 0;
}