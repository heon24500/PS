#include <iostream>
using namespace std;

int team1[6] = { 1, 2, 3, 3, 4, 10 };
int team2[7] = { 1, 2, 2, 2, 3, 5, 10 };

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int score1 = 0, score2 = 0;
		for (int i = 0; i < 6; i++) {
			int num;
			cin >> num;
			score1 += num * team1[i];
		}
		for (int i = 0; i < 7; i++) {
			int num;
			cin >> num;
			score2 += num * team2[i];
		}

		cout << "Battle " << tc << ": ";
		if (score1 > score2) cout << "Good triumphs over Evil\n";
		else if (score1 < score2) cout << "Evil eradicates all trace of Good\n";
		else cout << "No victor on this battle field\n";
	}

	return 0;
}