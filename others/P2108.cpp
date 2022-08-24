#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

double total = 0;
int N;
vector<int> v;
vector<int> modeV;
map<int, int> m;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        total += temp;
        v.push_back(temp);
        if (m.find(temp) != m.end()) {
            m[temp]++;
        } else {
            m[temp] = 1;
        }
    }

    sort(v.begin(), v.end());

    int maxVal = 0;
    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > maxVal) {
            maxVal = iter->second;
            modeV.clear();
            modeV.push_back(iter->first);
        } else if (iter->second == maxVal) {
            modeV.push_back(iter->first);
        }
    }

    sort(modeV.begin(), modeV.end());

    cout << int(round(total / N)) << endl;
    cout << v[N / 2] << endl;
    cout << (modeV.size() > 1 ? modeV[1] : modeV[0]) << endl;
    cout << v[N - 1] - v[0] << endl;

    return 0;
}