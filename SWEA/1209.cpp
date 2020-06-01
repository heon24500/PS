#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 10; i++) {
        int w_sum[100], h_sum[100], lr = 0, rl = 0;
        for (int j = 0; j < 100; j++) {
            w_sum[j] = 0;
            h_sum[j] = 0;
        }

        int test_case;
        cin >> test_case;

        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                int num;
                cin >> num;
                w_sum[j] += num;
                h_sum[k] += num;
                if (k == j) lr += num;
                if (k + j == 99) rl += num;
            }
        }

        sort(w_sum, w_sum + 100);
        sort(h_sum, h_sum + 100);
        int dia_max = max(lr, rl);
        int sum_max = max(w_sum[99], h_sum[99]);
        int ret = max(dia_max, sum_max);
        cout << "#" << test_case << " " << ret << "\n";
    }

    return 0;
}