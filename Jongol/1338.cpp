#include <iostream>
using namespace std;

char arr[100][100];
char ch = 'A';
int n;

void fill() {
	for (int i = 0; i < n; i++) {
		int k = n - 1;
		for (int j = i; j < n; j++) {
			arr[j][k--] = ch++;
			if (ch > 'Z') ch = 'A';
		}
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
	fill();
	print();

	return 0;
}