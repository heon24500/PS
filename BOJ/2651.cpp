#include <iostream>
using namespace std;

#define N 105
#define INF 1e9

int d[N], t[N], ret[N], path[N], cnt = 0, n;

void print_path(int x) {
    if (x == 0) {
        cout << cnt << "\n";
        return;
    }
    if (x != n + 1) cnt++;
    print_path(path[x]);
    if (x != n + 1) cout << x << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, max = 0;
    cin >> max >> n;
    for (int i = 0; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    t[n + 1] = 0;

    for (int i = 1; i <= n + 1; i++) {
        int dist = 0, mini = INF;
        for (int j = i - 1; j >= 0; j--) {
            dist += d[j];
            if (dist > max) break;
            int times = ret[j] + t[i];
            if (mini > times) {
                mini = times;
                p = j;
            }
        }
        ret[i] = mini;
        path[i] = p;
    }

    if (ret[n + 1] == 0) cout << "0\n0";
    else {
        cout << ret[n + 1] << "\n";
        print_path(n + 1);
    }

    return 0;
}