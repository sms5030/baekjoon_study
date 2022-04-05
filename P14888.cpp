#include <iostream> 
#include <vector>

using namespace std;

int N;
int valArr[20];
int opArr[4];
int resultMax = -2000000000, resultMin = 2000000000;

void FindMinMax(int idx, int result);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> valArr[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> opArr[i];
    }

    FindMinMax(0, valArr[0]);

    cout << resultMax << "\n";
    cout << resultMin << "\n";
}

void FindMinMax(int idx, int result) {
    if (idx == N - 1) {
        if (result > resultMax) {
            resultMax = result;
        }
        if (result < resultMin) {
            resultMin = result;
        }
    }

    else {
        int value = valArr[idx + 1];

        if (opArr[0] > 0) {
            opArr[0]--;
            FindMinMax(idx + 1, result + value);
            opArr[0]++;
        }

        if (opArr[1] > 0) {
            opArr[1]--;
            FindMinMax(idx + 1, result - value);
            opArr[1]++;
        }

        if (opArr[2] > 0) {
            opArr[2]--;
            FindMinMax(idx + 1, result * value);
            opArr[2]++;
        }

        if (opArr[3] > 0) {
            opArr[3]--;
            FindMinMax(idx + 1, result / value);
            opArr[3]++;
        }
    }
}
