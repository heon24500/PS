#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w, h, n;

int main() {
	cin >> w >> h >> n;
	vector<int> width, height;
	width.push_back(0);
	width.push_back(w);
	height.push_back(0);
	height.push_back(h);
	for (int i = 0; i < n; i++) {
		int d, num;
		cin >> d >> num;
		if (d == 1) width.push_back(num);
		else height.push_back(num);
	}

	sort(width.begin(), width.end());
	sort(height.begin(), height.end());
	int max_w = 0, max_h = 0;
	for (int i = 1; i < width.size(); i++) {
		int now = width[i] - width[i - 1];
		if (max_w < now) max_w = now;
	}
	for (int i = 1; i < height.size(); i++) {
		int now = height[i] - height[i - 1];
		if (max_h < now) max_h = now;
	}

	cout << max_w * max_h;

	return 0;
}