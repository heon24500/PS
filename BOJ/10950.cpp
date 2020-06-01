#include <iostream>
using namespace std;

int main() {
	int times, a, b;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}