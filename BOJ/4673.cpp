#include <iostream>
using namespace std;

int d(int);

int main() {
	int selfNum[20000];
	for (int i = 0; i < 10000; i++) {
		int n = d(i);
		selfNum[n] = 1;
	}

	for (int i = 0; i < 10000; i++) {
		if (selfNum[i] != 1) {
			cout << i << endl;
		}
	}

	return 0;
}

int d(int n) {
	int result = n;

	while (true) {
		if (n < 10) {
			result += n;
			return result;
		}
		else {
			result += n % 10;
			n /= 10;
		}
	}

	return result;
}