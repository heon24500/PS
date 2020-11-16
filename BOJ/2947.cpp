#include <iostream>
using namespace std;

int main() {
	int mat[5];
	for (int i = 0; i < 5; i++) cin >> mat[i];

	while (true) {
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			if (mat[i] > mat[i + 1]) {
				flag = true;
				swap(mat[i], mat[i + 1]);
				for (int j = 0; j < 5; j++) cout << mat[j] << ' ';
				cout << '\n';
			}
		}
		if (!flag) break;
	}

	return 0;
}