#include <iostream>
#include <vector>

using namespace std;

void MoveWheel (int x, int d, int k);
int GetWheelSpotPos(int x, int index);

int N, M, T, x, d, k;
int m[51][51] = { 0 };
int pos[51] = { 0 };

int main() {
  cin >> N >> M >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }

  for (int turn = 0; turn < T; turn++) {
    cin >> x >> d >> k;
    for (int i = x - 1; i < N; i += x) {
      MoveWheel(i, d, k);
    }

    vector<int> removeList;
    for (int i = 0; i < M; i++) {
      int curIdx = GetWheelSpotPos(0, i);
      if (m[0][curIdx] == 0) {
        continue;
      }

      int nextIdx = GetWheelSpotPos(0, i + 1);
      if (m[0][curIdx] == m[0][nextIdx]) {
        removeList.push_back(curIdx);
        removeList.push_back(nextIdx);
      }

      int bottomIdx = GetWheelSpotPos(1, i);
      if (m[0][curIdx] == m[1][bottomIdx]) {
        removeList.push_back(curIdx);
        removeList.push_back(1 * M + bottomIdx);
      }
    }

    for (int i = 1; i < N - 1; i++) {
      for (int j = 0; j < M; j++) {
        int curIdx = GetWheelSpotPos(i, j);
        if (m[i][curIdx] == 0) {
          continue;
        }

        int nextIdx = GetWheelSpotPos(i, j + 1);
        if (m[i][curIdx] == m[i][nextIdx]) {
          removeList.push_back(i * M + curIdx);
          removeList.push_back(i * M + nextIdx);
        }

        int upIdx = GetWheelSpotPos(i - 1, j);
        if (m[i][curIdx] == m[i - 1][upIdx]) {
          removeList.push_back(i * M + curIdx);
          removeList.push_back((i - 1) * M + upIdx);
        }

        int bottomIdx = GetWheelSpotPos(i + 1, j);
        if (m[i][curIdx] == m[i + 1][bottomIdx]) {
          removeList.push_back(i * M + curIdx);
          removeList.push_back((i + 1) * M + bottomIdx);
        }
      }
    }

    for (int i = 0; i < M; i++) {
      int curIdx = GetWheelSpotPos(N - 1, i);
      if (m[N - 1][curIdx] == 0) {
        continue;
      }

      int nextIdx = GetWheelSpotPos(N - 1, i + 1);
      if (m[N - 1][curIdx] == m[N - 1][nextIdx]) {
        removeList.push_back((N - 1) * M + curIdx);
        removeList.push_back((N - 1) * M + nextIdx);
      }

      int upIdx = GetWheelSpotPos(N - 2, i);
      if (m[N - 1][curIdx] == m[N - 2][upIdx]) {
        removeList.push_back((N - 1) * M + curIdx);
        removeList.push_back((N - 2) * M + upIdx);
      }
    }

    int removeCount = removeList.size();
    if (removeCount > 0) {
      for (int i = 0; i < removeCount; i++) {
        int index = removeList[i];
        m[index / M][index % M] = 0;
      }
    } else {
      int numTotal = 0;
      int numCount = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (m[i][j] != 0) {
            numTotal += m[i][j];
            numCount++;
          }
        }
      }
      if (numCount > 0) {
        int average = numTotal / numCount;
        int remain = numTotal % numCount;
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if (remain == 0) {
              if (m[i][j] > average) {
              m[i][j]--;
              } else if (0 < m[i][j] && m[i][j] < average) {
                m[i][j]++;
              }
            } else {
                if (m[i][j] > average) {
                m[i][j]--;
              } else if (0 < m[i][j] && m[i][j] <= average) {
                m[i][j]++;
              }
            }
          }
        }
      }
    }
  }

  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (m[i][j] != 0) {
        result += m[i][j];
      }
    }
  }
  cout << result << "\n";
}

void MoveWheel (int x, int d, int k) {
  if (d == 0) {
    pos[x] = (M + pos[x] - k) % M;
  } else if (d == 1) {
    pos[x] = (pos[x] + k) % M;
  }
  return;
}

int GetWheelSpotPos(int x, int index) {
  return (M + index + pos[x]) % M;
}