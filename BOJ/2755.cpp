#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	float total = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string subject, grade;
		float credit, subject_grade = 0.0;
		cin >> subject >> credit >> grade;
		if (grade == "A+") subject_grade = 4.3;
		else if (grade == "A+") subject_grade = 4.3;
		else if (grade == "A0") subject_grade = 4.0;
		else if (grade == "A-") subject_grade = 3.7;
		else if (grade == "B+") subject_grade = 3.3;
		else if (grade == "B0") subject_grade = 3.0;
		else if (grade == "B-") subject_grade = 2.7;
		else if (grade == "C+") subject_grade = 2.3;
		else if (grade == "C0") subject_grade = 2.0;
		else if (grade == "C-") subject_grade = 1.7;
		else if (grade == "D+") subject_grade = 1.3;
		else if (grade == "D0") subject_grade = 1.0;
		else if (grade == "D-") subject_grade = 0.7;
		else if (grade == "F") subject_grade = 0.0;
		total += credit * subject_grade;
		sum += credit;
	}

	cout.precision(2);
	cout << fixed;
	cout << total / sum;

	return 0;
}