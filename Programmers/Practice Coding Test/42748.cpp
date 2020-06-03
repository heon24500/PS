#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int cnt = 0; cnt < commands.size(); cnt++) {
        int i = commands[cnt][0];
        int j = commands[cnt][1];
        int k = commands[cnt][2];

        vector<int> temp;
        for (int t = i - 1; t < j; t++) {
            temp.push_back(array[t]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }

    return answer;
}