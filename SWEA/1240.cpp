/* 1240. [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드 */
#include <iostream>
using namespace std;

const int N = 51;
const int M = 101;
char mat[N][M];

int valid(char* ch)
{
	int nums[9];
	for (int i = 0; i <= 49; i += 7) {
		int num = 0;
		string str;
		for (int j = 0; j < 7; j++) {
			str += ch[j + i];
		}
		if (str == "0001101") num = 0;
		else if (str == "0011001") num = 1;
		else if (str == "0010011") num = 2;
		else if (str == "0111101") num = 3;
		else if (str == "0100011") num = 4;
		else if (str == "0110001") num = 5;
		else if (str == "0101111") num = 6;
		else if (str == "0111011") num = 7;
		else if (str == "0110111") num = 8;
		else if (str == "0001011") num = 9;
		nums[i / 7 + 1] = num;
	}

	int odd = 0, even = 0;
	for (int i = 1; i <= 7; i++) {
		if (i % 2 == 0) even += nums[i];
		else odd += nums[i];
	}

	int ret = odd * 3 + even + nums[8];
	if (ret % 10 == 0) {
		int sum = 0;
		for (int i = 1; i <= 8; i++) {
			sum += nums[i];
		}
		return sum;
	}
	else return 0;
}

void init()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = NULL;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m;
		cin >> n >> m;
		int y, x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
				if (mat[i][j] == '1') {
					y = i;
					x = j;
				}
			}
		}

		char nums[56];
		for (int i = 0; i < 56; i++) {
			nums[i] = mat[y][x - 56 + 1 + i];
		}
		int ret = valid(nums);
		cout << "#" << tc << " " << ret << '\n';
		init();
	}

	return 0;
}