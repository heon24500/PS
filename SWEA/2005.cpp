#include <iostream>
#include <vector>
using namespace std;

#define N 15
vector<int> v[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "#" << i << "\n";
        int n;
        cin >> n;

        v[1].push_back(1);
        v[1].push_back(1);

        cout << "1\n";
        if (n >= 2) {
            cout << "1 1\n";
            for (int j = 2; j < n; j++) {
                cout << "1 ";
                v[j].push_back(1);
                for (int k = 0; k < j - 1; k++) {
                    int num = v[j - 1][k] + v[j - 1][k + 1];
                    v[j].push_back(num);
                    cout << num << " ";
                }
                cout << "1\n";
                v[j].push_back(1);
            }
        }
    }

    return 0;
}