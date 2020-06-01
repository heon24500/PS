using namespace std;
#include <iostream>

int main() {
	int a, b, c;
	int mid;

	cin >> a >> b >> c;
	if (a > b) {
		if (b > c) {  // a > b > c
			mid = b;
		}
		else {
			if (c > a) {  // c > a > b
				mid = a;
			}
			else {  // a > c > b
				mid = c;
			}
		}
	}
	else {
		if (a > c) {  // b > a > c
			mid = a;
		}
		else {
			if (c > b) {  // c > b > a
				mid = b;
			}
			else {  // b > c > a
				mid = c;
			}
		}
	}

	cout << mid << endl;

	return 0;
}