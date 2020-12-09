#include <iostream>
using namespace std;

int arr[100][100];
int n, num = 1;

void fill() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[j][i] = num++;
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