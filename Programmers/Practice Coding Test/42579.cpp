#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> psi;
typedef pair<int, int> pii;

bool comp(psi a, psi b) {
    return a.second > b.second;
}

bool compare(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> m;
    for (int i = 0; i < genres.size(); i++) m[genres[i]] += plays[i];

    vector<psi> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        string g = v[i].first;
        vector<pii> temp;
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == g) temp.push_back({ plays[j], j });
        }
        sort(temp.begin(), temp.end(), compare);
        int cnt = 0;
        for (int j = 0; j < temp.size(); j++) {
            cnt++;
            if (cnt > 2) break;
            answer.push_back(temp[j].second);
        }
    }

    return answer;
}