#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int p;
		cin >> p;

		ll max_price = 0;
		string name;
		while (p--) {
			ll price;
			string str;
			cin >> price >> str;
			if (price > max_price) {
				max_price = price;
				name = str;
			}
		}
		cout << name << '\n';
	}

	return 0;
}