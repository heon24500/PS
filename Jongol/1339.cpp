#include <iostream>
using namespace std;

char arr[100][100];
char ch = 'A';
int n;

void fill() {
	int cnt = 1;
	for (int i = (n - 1) / 2; i >= 0; i--) {
		for (int j = i; j < i + cnt; j++) {
			arr[j][i] = ch++;
			if (ch > 'Z') ch = 'A';
		}
		cnt += 2;
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == NULL) cout << "  ";
			else cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n >= 1 && n <= 100 && n % 2 != 0) {
		fill();
		print();
	}
	else cout << "INPUT ERROR\n";

	return 0;
}