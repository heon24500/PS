#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int now[3];
		now[0] = stoi(str.substr(0, 2));
		now[1] = stoi(str.substr(3, 2));
		now[2] = stoi(str.substr(6, 2));

		int time[3][6] = { 0 };
		for (int i = 0; i < 3; i++) {
			int nt = now[i];
			int val = 32, idx = 0;
			while (nt > 0) {
				if (nt >= val) {
					time[i][idx] = nt / val;
					nt -= val;
				}
				val /= 2;
				idx++;
			}
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cout << time[j][i];
			}
		}
		cout << " ";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				cout << time[i][j];
			}
		}
		cout << '\n';
	}

	return 0;
}