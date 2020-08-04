/* 9461. 파도반 수열 */
#include <iostream>
using namespace std;

const int N = 101;
long long p[N];

int main()
{
	p[1] = 1, p[2] = 1, p[3] = 1;
	p[4] = 2, p[5] = 2;
	for (int i = 6; i < N; i++) {
		p[i] = p[i - 1] + p[i - 5];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << p[n] << '\n';
	}

	return 0;
}