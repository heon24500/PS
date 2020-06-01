#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> VN;
    for (int i = 0; i < N; i++) {
        int Ni;
        cin >> Ni;
        for (int j = 0; j < Ni; j++) {
            VN.push_back(i + 1);
        }
    }

    for (int i = 0; i < Q; i++) {
        int Qi;
        cin >> Qi;
        cout << VN[Qi] << "\n";
    }
}