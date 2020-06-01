#include <iostream>
using namespace std;

int main() {
	int times, num_circles, min = 0;
	int start_x, start_y, end_x, end_y;
	int dis_x, dis_y;
	int x, y, r;

	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> start_x >> start_y >> end_x >> end_y;
		cin >> num_circles;
		for (int j = 0; j < num_circles; j++) {
			cin >> x >> y >> r;

			dis_x = start_x - x;
			dis_y = start_y - y;
			if (((dis_x * dis_x) + (dis_y * dis_y)) < (r * r)) {
				dis_x = end_x - x;
				dis_y = end_y - y;
				if (((dis_x * dis_x) + (dis_y * dis_y)) < (r * r)) {}
				else min++;
			}
			else {
				dis_x = end_x - x;
				dis_y = end_y - y;
				if (((dis_x * dis_x) + (dis_y * dis_y)) < (r * r)) min++;
			}
		}

		cout << min << endl;
		min = 0;
	}
	return 0;
}