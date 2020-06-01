#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ret, ret2;
    int N, K, num;
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        char ch;
        cin >> num >> ch;
        ret.push_back(num);
    }
    cin >> num;
    ret.push_back(num);

    for (int i = 0; i < K; i++) {
        ret2.clear();
        for (int i = 1; i < ret.size(); i++) {
            ret2.push_back(ret[i] - ret[i - 1]);
        }
        ret = ret2;
    }

    for (int i = 0; i < ret.size() - 1; i++) {
        cout << ret[i] << ",";
    }
    cout << ret[ret.size() - 1];
}