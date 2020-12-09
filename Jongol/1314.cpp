#include <iostream>
using namespace std;

char arr[100][100];
char ch = 'A';
int n;

void fill() {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				arr[j][i] = ch++;
				if (ch > 'Z') ch = 'A';
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				arr[j][i] = ch++;
				if (ch > 'Z') ch = 'A';
			}
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill();
	print();

	return 0;
}