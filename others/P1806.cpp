#include <iostream>
#include <vector>

using namespace std;

int N, S, temp;
vector<int> v;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (v.size() == 0) {
            v.push_back(temp);
        } else {
            v.push_back(v[i - 1] + temp);
        }
    }

    if (v[N - 1] < S) {
        cout << 0 << "\n";
        return 0;
    }

    bool isFirst = true;
    int minLen = 1000000;
    for (int i = 0; i < N; i++) {
        if (isFirst) {
            if (v[i] >= S) {
                for (int j = 0; j <= i; j++) {
                    if (v[i] - v[j] < S) {
                        minLen = i - j + 1;
                        break;
                    }
                }
                isFirst = false;
            }
        } else {
            if (v[i] - v[i - minLen + 1] >= S) {
                for (int j = i - minLen + 2; j <= i; j++) {
                    if (v[i] - v[j] < S) {
                        minLen = i - j + 1;
                        break;
                    }
                }
            }
        }
    }
    cout << minLen << "\n";
    return 0;
}