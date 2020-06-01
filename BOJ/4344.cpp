#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int c, n;
	double* grade;

	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;
		grade = new double[n];
		for (int j = 0; j < n; j++) {
			cin >> grade[j];
		}

		double sum = 0;
		for (int j = 0; j < n; j++) {
			sum += grade[j];
		}

		double avg = sum / (double)n;
		int aboveAvg = 0;
		for (int j = 0; j < n; j++) {
			if (grade[j] > avg) {
				aboveAvg++;
			}
		}

		double numAboveAvg = (double)aboveAvg / (double)n * 100;
		printf("%.3f%%\n", numAboveAvg);
	}

	return 0;
}