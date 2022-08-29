#include <iostream>
#include <vector>

using namespace std;

int FibRecursion(int N);
int FibDP(int N);

int recursionCount = 0, dpCount = 0;
vector<int> dp;

int main() {
    int N;
    cin >> N;

    FibRecursion(N);
    FibDP(N);

    cout << recursionCount << " " << dpCount << "\n";
    return 0;
}

int FibRecursion(int N) {
    if (N == 1 || N == 2) {
        recursionCount++;
        return 1;
    } else {
        return FibRecursion(N - 1) + FibRecursion(N - 2);
    }

}

int FibDP(int N) {
    dp.push_back(1); // N == 1
    dp.push_back(1); // N == 2
    for(int i = 2; i < N; i++) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
        dpCount++;
    }

    return dp[N - 1];
}
