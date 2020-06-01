#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> VN;
    for (int i = N; i >= 1; i--) {
        VN.push_back(i);
    }

    while (VN.size() > 1) {
        cout << VN[VN.size() - 1] << " ";
        VN.pop_back();
        VN.insert(VN.begin(), VN[VN.size() - 1]);
        VN.pop_back();
    }

    cout << VN[0];
}