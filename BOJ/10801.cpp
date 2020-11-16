#include <iostream>
using namespace std;

int main() {
	int cnt[2] = { 0 };
	int cards[10];
	for (int i = 0; i < 10; i++) cin >> cards[i];
	for (int i = 0; i < 10; i++) {
		int card;
		cin >> card;
		if (cards[i] > card) cnt[0]++;
		if (cards[i] < card) cnt[1]++;
	}

	if (cnt[0] > cnt[1]) cout << "A";
	else if (cnt[0] < cnt[1]) cout << "B";
	else cout << "D";

	return 0;
}