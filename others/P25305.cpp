#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, k, temp;
vector<int> v;

int main() {
    cin >> N >> k;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<int>());

    cout << v[k-1] << endl;
    return 0;
}