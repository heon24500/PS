#include <iostream>
using namespace std;

typedef long long ll;

ll my_pow(ll a, ll b, ll c) {
	if (b == 0) return 1;
	ll ret = my_pow(a, b / 2, c);
	ret = (ret * ret) % c;

	if (b % 2 == 0) return ret;
	else return (ret * a) % c;
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << my_pow(a, b, c);

	return 0;
}