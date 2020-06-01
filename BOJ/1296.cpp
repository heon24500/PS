#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int ms_l = 0, ms_o = 0, ms_v = 0, ms_e = 0;
	string ms;
	cin >> ms;

	for (int i = 0; i < ms.length(); i++) {
		if (ms[i] == 'L') ms_l++;
		else if (ms[i] == 'O') ms_o++;
		else if (ms[i] == 'V') ms_v++;
		else if (ms[i] == 'E') ms_e++;
	}

	string girl[50];
	int N, max = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> girl[i];
	}

	sort(girl, girl + N);
	string choice = girl[0];
	for (int i = 0; i < N; i++) {
		int L = ms_l, O = ms_o, V = ms_v, E = ms_e;

		for (int j = 0; j < girl[i].length(); j++) {
			if (girl[i][j] == 'L') L++;
			else if (girl[i][j] == 'O') O++;
			else if (girl[i][j] == 'V') V++;
			else if (girl[i][j] == 'E') E++;
		}

		int result = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

		if (max < result) {
			max = result;
			choice = girl[i];
		}
	}

	cout << choice;
}