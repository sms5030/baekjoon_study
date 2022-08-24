#include <iostream>
#include <vector>

using namespace std;

void HanoiTop(int N, int begin, int temp, int end);
int N;
vector<pair<int, int> > v;

int main() {
    cin >> N;
    HanoiTop(N, 1, 2, 3);

    int length = v.size();
    cout << length << endl;
    for (int i = 0; i < length; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}

void HanoiTop(int N, int begin, int temp, int end) {
    if (N == 1) {
        v.push_back(make_pair(begin, end));
    }
    else {
        HanoiTop(N - 1, begin, end, temp);
        v.push_back(make_pair(begin, end));
        HanoiTop(N - 1, temp, begin, end);
    }
}