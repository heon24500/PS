#include <iostream>
using namespace std;

int main() {
	int n, cycle = 0;

	cin >> n;
	int org_n = n;

	while (true) {
		int a = n / 10;
		int b = n % 10;

		int new_a = b;
		int new_b = (a + b) % 10;
		int new_n = new_a * 10 + new_b;

		cycle++;

		if (new_n == org_n) {
			break;
		}
		else {
			n = new_n;
		}
	}

	cout << cycle << endl;

	return 0;
}