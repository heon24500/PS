#include <iostream>
using namespace std;

int Sangsu(int);

int main() {
	int org_a, org_b;
	cin >> org_a >> org_b;

	int ss_a = Sangsu(org_a);
	int ss_b = Sangsu(org_b);

	if (ss_a > ss_b) {
		cout << ss_a << endl;
	}
	else {
		cout << ss_b << endl;
	}

	return 0;
}

int Sangsu(int n) {
	int a = n % 10;
	int b = n / 10;
	int c = b / 10;
	b %= 10;

	int sangsu = a * 100 + b * 10 + c;

	return sangsu;
}