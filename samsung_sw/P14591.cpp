#include <iostream>

using namespace std;

int N;
int timeArr[20];
int payArr[20];
int maxResult = 0;

void GetMaxIncome(int idx, int result);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> timeArr[i] >> payArr[i];
    }

    GetMaxIncome(0, 0);

    cout << maxResult << endl;
    return 0;
}

void GetMaxIncome(int idx, int result) {
    if (idx > N - 1) {
        if (result > maxResult) {
            maxResult = result;
        }
        return;
    } 

    while (idx + timeArr[idx] > N) {
        idx++;

        if (idx > N - 1) {
            if (result > maxResult) {
                maxResult = result;
            }
            return;
        }
    }

    GetMaxIncome(idx + timeArr[idx], result + payArr[idx]);  // Adjust
    GetMaxIncome(idx + 1, result); // Pass
}