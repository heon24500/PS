#include <iostream>
using namespace std;

typedef struct Rect {
	int sx;
	int sy;
	int dx;
	int dy;
} Rect;

char check(Rect r1, Rect r2) {
	if (r1.sy > r2.dy || r2.sy > r1.dy || r1.sx > r2.dx || r2.sx > r1.dx) return 'd';
	if ((r1.dx == r2.sx && r1.dy == r2.sy) || (r1.dx == r2.sx && r1.sy == r2.dy) || (r1.sx == r2.dx && r1.sy == r2.dy) || (r1.sx == r2.dx && r1.dy == r2.sy)) return 'c';
	if (r1.dx == r2.sx || r1.sx == r2.dx || r1.sy == r2.dy || r1.dy == r2.sy) return 'b';
	return 'a';
}

int main() {
	for (int i = 0; i < 4; i++) {
		Rect r[2];
		for (int j = 0; j < 2; j++) {
			int sx, sy, dx, dy;
			cin >> sx >> sy >> dx >> dy;
			r[j] = { sx, sy, dx, dy };
		}
		cout << check(r[0], r[1]) << '\n';
	}

	return 0;
}