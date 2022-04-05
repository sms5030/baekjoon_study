#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[51][51] = { 0 };
vector<int> homeList;
vector<int> chickenList;
int minResult = 1000000000;

void FindMinDistance(int L, int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                homeList.push_back(i * N + j);
            }
            if (arr[i][j] == 2) {
                chickenList.push_back(i * N + j);
            }
        }
    }

    int chickenLen = chickenList.size();
    FindMinDistance(chickenLen - M, 0);
    cout << minResult << endl;
    return 0;
}

void FindMinDistance(int L, int idx) {
    cout << L << " " << idx << "\n";

    if (L == 0) {
        int result = 0;
        int homeLen = homeList.size();
        int chickenLen = chickenList.size();
        for (int i = 0; i < homeLen; i++) {
            int minDistance = 10000;
            for (int j = 0; j < chickenLen; j++) {
                if (chickenList[j] > 0) {
                    int homeI = homeList[i] / N;
                    int homeJ = homeList[i] % N;
                    int chickenI = chickenList[j] / N;
                    int chickenJ = chickenList[j] % N;
                    int distance = (homeI > chickenI ? homeI - chickenI : chickenI - homeI) + (homeJ > chickenJ ? homeJ - chickenJ : chickenJ - homeJ);
                    
                    if (distance < minDistance) {
                        minDistance = distance;
                    }
                }
            }
            result += minDistance;
        }

        if (result < minResult) {
            for (int i = 0; i < chickenLen; i++) {
                cout << chickenList[i] << " ";
            }
            cout << "\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << arr[i][j] << " " ;
                }
                cout << "\n";
            }


            minResult = result;
            cout << minResult << endl;
        }
        return;
    }

    int chickenLen = chickenList.size();
    if (chickenLen < idx) {
        return;
    }

    for (int i = idx; i < chickenLen; i++) {
        int savedValue = chickenList[i];
        chickenList[i] = -1;
        FindMinDistance(L - 1, idx + 1);
        chickenList[i] = savedValue;
    }
}