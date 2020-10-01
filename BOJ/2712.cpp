#include <iostream>
using namespace std;

void trans(double d, string s) {
	if (s == "kg") {
		cout << d * 2.2046 << " lb\n";
		return;
	}
	if (s == "lb") {
		cout << d * 0.4536 << " kg\n";
		return;
	}
	if (s == "l") {
		cout << d * 0.2642 << " g\n";
		return;
	}
	if (s == "g") {
		cout << d * 3.7854 << " l\n";
	}
}

int main() {
	cout << fixed;
	cout.precision(4);

	int t;
	cin >> t;
	while (t--) {
		double d;
		string s;
		cin >> d >> s;
		trans(d, s);
	}

	return 0;
}