/* 1245. [S/W 문제해결 응용] 2일차 - 균형점 */
#include <iostream>
using namespace std;

const int N = 10;
int x[N], m[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}

		cout << fixed;
		cout.precision(10);
		cout << "#" << tc << ' ';
		for (int i = 0; i < n - 1; i++) {
			double left = x[i], right = x[i + 1];
			double ret = 0;
			for (int j = 0; j < 100; j++) {
				double mid = (left + right) / 2;
				double sum = 0;
				for (int k = 0; k <= i; k++) {
					sum += m[k] / ((mid - x[k]) * (mid - x[k]));
				}
				for (int k = i + 1; k < n; k++) {
					sum -= m[k] / ((mid - x[k]) * (mid - x[k]));
				}

				if (sum > 0) left = mid;
				else {
					ret = mid;
					right = mid;
				}
			}
			cout << ret << ' ';
		}
		cout << '\n';
	}

	return 0;
}