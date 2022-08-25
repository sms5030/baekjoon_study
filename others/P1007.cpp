#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

void FindMinValue(int n, int index, bool isMinus[]);

int T, N, x, y;
vector<pair<int, int> > v;
bool isMinus[20] = { false };
double minValue = DBL_MAX;

int main() {
    cout.precision(12);

    cin >> T;
    for (int turn = 0; turn < T; turn++) {
        v.clear();
        minValue = DBL_MAX;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }

        for (int i = 0; i < N / 2; i++) {
            isMinus[i] = true;
            FindMinValue(1, i, isMinus);
            isMinus[i] = false;
        }
        cout << fixed << minValue << endl;
    }
    return 0;
}

void FindMinValue(int n, int index, bool isMinus[]) {
    if (n == N / 2) {
        int length = v.size();
        double totalX = 0.0, totalY = 0.0;
        for (int i = 0; i < length; i++) {
            totalX += (v[i].first * (isMinus[i] ? -1 : 1));
            totalY += (v[i].second * (isMinus[i] ? -1 : 1));
        }

        double value = sqrt(totalX * totalX + totalY * totalY);
        if (minValue > value) {
            minValue = value;
        }
    } else {
        for (int i = index + 1; i < N / 2 + n; i++) {
            isMinus[i] = true;
            FindMinValue(n + 1, i, isMinus);
            isMinus[i] = false;
        }
    }
}