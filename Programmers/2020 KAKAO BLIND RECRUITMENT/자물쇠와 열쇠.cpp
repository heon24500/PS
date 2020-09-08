#include <string>
#include <vector>

using namespace std;

vector<vector<int> > lotateKey(vector<vector<int> > key) {
    int m = key.size();
    vector<vector<int> > ret;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = m - 1; j >= 0; j--) {
            temp.push_back(key[j][i]);
        }
        ret.push_back(temp);
    }
    return ret;
}

bool placeKey(vector<vector<int> > key, vector<vector<int> > lock, int y, int x) {
    vector<vector<int> > ret = lock;
    for (int i = y; i < y + key.size(); i++) {
        for (int j = x; j < x + key.size(); j++) {
            if (ret[i][j] == 1 && key[i - y][j - x] == 1) return false;
            if (ret[i][j] == 0 && key[i - y][j - x] == 1) ret[i][j] = key[i - y][j - x];
        }
    }

    int len = lock.size() / 3;
    for (int i = len; i < len * 2; i++) {
        for (int j = len; j < len * 2; j++) {
            if (ret[i][j] == 0) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    vector<vector<int> > newLock;

    int cnt = 0;
    for (int i = 0; i < n * 3; i++) {
        vector<int> temp;
        for (int j = 0; j < n * 3; j++) {
            if (i >= n && i < n * 2 && j >= n && j < n * 2) {
                temp.push_back(lock[i - n][j - n]);
                if (lock[i - n][j - n] == 0) cnt++;
            }
            else temp.push_back(0);
        }
        newLock.push_back(temp);
    }

    int m = key.size();
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < n * 3 - m; i++) {
            for (int j = 0; j < n * 3 - m; j++) {
                if (placeKey(key, newLock, i, j)) return true;
            }
        }
        key = lotateKey(key);
    }

    return false;
}