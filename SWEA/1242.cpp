/* 1242. [S/W 문제해결 응용] 1일차 - 암호코드 스캔 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2001;
int mat[N][N];
int code[5][5][5];
int hCode[16][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 1 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 1, 1 },
	{ 0, 1, 0, 0 },
	{ 0, 1, 0, 1 },
	{ 0, 1, 1, 0 },
	{ 0, 1, 1, 1 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 1 },
	{ 1, 0, 1, 0 },
	{ 1, 0, 1, 1 },
	{ 1, 1, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 1, 1, 1, 0 },
	{ 1, 1, 1, 1 }
};

int valid(int *arr)
{
	int even = 0, odd = 0, sum = arr[7], ret = arr[7];
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0) odd += arr[i];
		else even += arr[i];
		sum += arr[i];
	}
	ret += odd * 3 + even;
	if (ret % 10 == 0) return sum;
	else return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	// 비율에 따른 암호코드 값 설정 (첫번째 0 없이도 값 설정 가능)
	code[2][1][1] = 0;
	code[2][2][1] = 1;
	code[1][2][2] = 2;
	code[4][1][1] = 3;
	code[1][3][2] = 4;
	code[2][3][1] = 5;
	code[1][1][4] = 6;
	code[3][1][2] = 7;
	code[2][1][3] = 8;
	code[1][1][2] = 9;

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m;
		cin >> n >> m;
		// 입력 값 바로 2진수로 변환하여 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char ch;
				cin >> ch;
				if (ch <= '9') ch = ch - '0';
				else ch = ch - 'A' + 10;
				for (int k = 0; k < 4; k++) {
					mat[i][j * 4 + k] = hCode[ch][k];
				}
			}
		}

		// 뒤에서부터 확인하며 1이 나오면 숫자열 시작
		int ret[8], idx = 7, ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = m * 4 - 1; j >= 0; j--) {
				int cnt[4] = { 0, 0, 0, 0 };
				if (mat[i][j] == 1 && mat[i - 1][j] == 0) {
					while (mat[i][j] == 1) { cnt[2]++; j--; }
					while (mat[i][j] == 0) { cnt[1]++; j--; }
					while (mat[i][j] == 1) { cnt[0]++; j--; }
					j++;

					int min_cnt = min(cnt[0], min(cnt[1], cnt[2]));
					for (int k = 0; k < 3; k++) { cnt[k] /= min_cnt; };
					ret[idx--] = code[cnt[0]][cnt[1]][cnt[2]];
					if (idx == -1) {
						ans += valid(ret);
						idx = 7;
					}
				}
			}
		}

		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}