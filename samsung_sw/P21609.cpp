#include <iostream>
#include <vector>

using namespace std;

void FindGroup(int color, int i, int j);
void AfterGravity();
void RotateCCW();

int N, M;
int m[21][21] = { 0 };
bool isVisited[21][21] = { false };
int maxNum = 0, maxRainbow = 0, maxBaseIndex = -1, num = 0, rainbow = 0, baseIndex = 0;
vector<int> maxIndice, indice;

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> m[i][j];
    }
  }

  int totalScore = 0;
  bool isContinue = true;
  while (isContinue) {
    isContinue = false;

    maxNum = 0;
    maxRainbow = 0;
    maxIndice.clear();
    maxBaseIndex = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (m[i][j] > 0) {
          for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
              isVisited[i][j] = false;
            }
          }

          num = 0;
          rainbow = 0;
          baseIndex = N * N + 1;
          indice.clear();
          FindGroup(m[i][j], i, j);

          if ((maxNum < num) || (maxNum == num && maxRainbow < rainbow) || (maxNum == num && maxRainbow == rainbow && maxBaseIndex < baseIndex)) {
            maxNum = num;
            maxRainbow = rainbow;
            maxBaseIndex = baseIndex;
            maxIndice = indice;
          }
        }
      }
    }
    if (maxNum > 1) {
      isContinue = true;
      int length = maxIndice.size();
      for(int l = 0; l < length; l++) {
        int index = maxIndice[l];
        m[index / N][index % N] = -2;
      }
      totalScore += (maxNum * maxNum);

      AfterGravity();
      RotateCCW();
      AfterGravity();
    }
  }

  cout << totalScore << endl;
  return 0;
}

void FindGroup(int color, int i, int j) {
  isVisited[i][j] = true;
  num++;
  if (m[i][j] == 0) {
    rainbow++;
  }
  if (m[i][j] > 0 && baseIndex > i * N + j) {
    baseIndex = i * N + j;
  }
  indice.push_back(i * N + j);

  if (i + 1 < N && isVisited[i + 1][j] == false && (m[i + 1][j] == color || m[i + 1][j] == 0)) {
    FindGroup(color, i + 1, j);
  }

  if (i - 1 >= 0 && isVisited[i - 1][j] == false && (m[i - 1][j] == color || m[i - 1][j] == 0)) {
    FindGroup(color, i - 1, j);
  }

  if (j + 1 < N && isVisited[i][j + 1] == false && (m[i][j + 1] == color || m[i][j + 1] == 0)) {
    FindGroup(color, i, j + 1);
  }

  if (j - 1 >= 0 && isVisited[i][j - 1] == false && (m[i][j - 1] == color || m[i][j - 1] == 0)) {
    FindGroup(color, i, j - 1);
  }
}

void AfterGravity() {
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      if (m[i][j] > -1 && m[i + 1][j] == -2) {
        for (int k = i; k < N - 1; k++) {
          if (m[k + 1][j] > -2) {
            break;
          }
          m[k + 1][j] = m[k][j];
          m[k][j] = -2;
        }
      }
    }
  }
}

void RotateCCW() {
  int newM[21][21] = { 0 };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      newM[N - 1 - j][i] = m[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      m[i][j] = newM[i][j];
    }
  }
}