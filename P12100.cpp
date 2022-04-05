#include <iostream>
#include <vector>
#include <string>


using namespace std;

int N;
int maxVal = 0;

void MoveUp(vector<vector<int> > v, int T, string h);
void MoveDown(vector<vector<int> > v, int T, string h);
void MoveLeft(vector<vector<int> > v, int T, string h);
void MoveRight(vector<vector<int> > v, int T, string h);

int main() {
    cin >> N;
    vector<vector<int> > v;
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        v.push_back(temp);
        for (int j = 0; j < N ; j++) {
            int value;
            cin >> value;
            v[i].push_back(value);
        }
    }

    MoveUp(v, 5, "U");
    MoveDown(v, 5, "D");
    MoveLeft(v, 5, "L");
    MoveRight(v, 5, "R");

    cout << maxVal << endl;

    return 0;
}

void MoveUp(vector<vector<int> > v, int T, string h) {
    bool isMerged[20][20] = { false };

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos > 0 && v[pos - 1][j] == 0) {
                v[pos - 1][j] = v[pos][j];
                v[pos][j] = 0; 
                pos--;
            }

            if (pos > 0 && isMerged[pos - 1][j] == false && v[pos - 1][j] == v[pos][j]) {
                v[pos - 1][j] *= 2;
                v[pos][j] = 0;
                isMerged[pos -1][j] = true;
            }
        }
    }

    if (T == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxVal < v[i][j]) {
                    maxVal = v[i][j];
                }
            }
        }
        return;
    } else {
        MoveUp(v, T - 1, h + 'U');
        MoveDown(v, T - 1, h + 'D');
        MoveLeft(v, T - 1, h + 'L');
        MoveRight(v, T - 1, h + 'R');
    }
}

void MoveDown(vector<vector<int> > v, int T, string h) {
    bool isMerged[20][20] = { false };

    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos + 1 < N && v[pos + 1][j] == 0) {
                v[pos + 1][j] = v[pos][j];
                v[pos][j] = 0; 
                pos++;
            }

            if (pos + 1 < N && isMerged[pos + 1][j] == false && v[pos + 1][j] == v[pos][j]) {
                v[pos + 1][j] *= 2;
                v[pos][j] = 0;
                isMerged[pos + 1][j] = true;
            }
        }
    }

    if (T == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxVal < v[i][j]) {
                    maxVal = v[i][j];
                }
            }
        }
        return;
    } else {
        MoveUp(v, T - 1, h + 'U');
        MoveDown(v, T - 1, h + 'D');
        MoveLeft(v, T - 1, h + 'L');
        MoveRight(v, T - 1, h + 'R');
    }
}

void MoveLeft(vector<vector<int> > v, int T, string h) {
    bool isMerged[20][20] = { false };

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos > 0 && v[j][pos - 1] == 0) {
                v[j][pos - 1] = v[j][pos];
                v[j][pos] = 0; 
                pos--;
            }

            if (pos > 0 && isMerged[j][pos - 1] == false && v[j][pos - 1] == v[j][pos]) {
                v[j][pos - 1] *= 2;
                v[j][pos] = 0;
                isMerged[j][pos - 1] = true;
            }
        }
    }

    if (T == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxVal < v[i][j]) {
                    maxVal = v[i][j];
                }
            }
        }
        return;
    } else {
        MoveUp(v, T - 1, h + 'U');
        MoveDown(v, T - 1, h + 'D');
        MoveLeft(v, T - 1, h + 'L');
        MoveRight(v, T - 1, h + 'R');
    }
}

void MoveRight(vector<vector<int> > v, int T, string h) {
    bool isMerged[20][20] = { false };

    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            int pos = i;
            while (pos + 1 < N && v[j][pos + 1] == 0) {
                v[j][pos + 1] = v[j][pos];
                v[j][pos] = 0; 
                pos++;
            }

            if (pos + 1 < N && isMerged[j][pos + 1] == false && v[j][pos + 1] == v[j][pos]) {
                v[j][pos + 1] *= 2;
                v[j][pos] = 0;
                isMerged[j][pos + 1] = true;
            }
        }
    }
    
    if (T == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxVal < v[i][j]) {
                    maxVal = v[i][j];
                }
            }
        }
        return;
    } else {
        MoveUp(v, T - 1, h + 'U');
        MoveDown(v, T - 1, h + 'D');
        MoveLeft(v, T - 1, h + 'L');
        MoveRight(v, T - 1, h + 'R');
    }
}