#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int w = 0, k = 0;
	vector<int> vw(10), vk(10);
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		vw[i] = n;
	}
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		vk[i] = n;
	}
	sort(vw.begin(), vw.end());
	sort(vk.begin(), vk.end());
	for (int i = 7; i < 10; i++) {
		w += vw[i];
		k += vk[i];
	}

	cout << w << ' ' << k;


	return 0;
}