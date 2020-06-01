#include <iostream>
using namespace std;

int main() {
	int n;
	double m, * grade, avg = 0;

	cin >> n;
	grade = new double[n];

	for (int i = 0; i < n; i++) {
		cin >> grade[i];
	}

	m = grade[0];
	for (int i = 1; i < n; i++) {
		if (grade[i] > m) {
			m = grade[i];
		}
	}

	for (int i = 0; i < n; i++) {
		grade[i] = grade[i] / m * 100;
	}

	for (int i = 0; i < n; i++) {
		avg += grade[i];
	}

	avg /= n;
	cout << avg << endl;

	return 0;
}