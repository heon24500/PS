#include <iostream>
using namespace std;

#define W 1005
int mat[W];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 10; i++) {
        int t, sight = 0;
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> mat[j];
        }

        for (int j = 2; j < t - 2; j++) {
            int left = mat[j] - max(mat[j - 1], mat[j - 2]);
            int right = mat[j] - max(mat[j + 1], mat[j + 2]);
            if (left > 0 && right > 0) sight += min(left, right);
        }

        cout << "#" << i << " " << sight << "\n";
    }

    return 0;
}