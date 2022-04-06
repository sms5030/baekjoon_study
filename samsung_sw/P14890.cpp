#include <iostream>

using namespace std;

int N, L;
int map[101][101] = { 0 };
int main() {
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  int result = 0;
  for (int i = 0; i < N; i++) {
    int isArrived = true;
    int repeat = 1;
    int height = map[i][0];
    for (int j = 1; j < N; j++) {
      if (map[i][j] == height) {
        repeat++;
      } else {
        if (map[i][j] - height == 1 && L <= repeat) {
          height = map[i][j];
          repeat = 1;
        } else if (height - map[i][j] == 1) {
          int count = 0;
          for (int k = j; k < N; k++) {
            if (map[i][j] != map[i][k]) {
              isArrived = false;
              break;
            } else {
              count++;
              if (count == L) {
                height = map[i][j];
                repeat = 0;
                j = k;
                break;
              }
            }
          }
          if (count < L) {
            isArrived = false;
          }
        } else {
          isArrived = false;
          break;
        }
      }
    }
    if (isArrived) {
      result++;
    }
  }

  for (int i = 0; i < N; i++) {
    int isArrived = true;
    int repeat = 1;
    int height = map[0][i];
    for (int j = 1; j < N; j++) {
      if (map[j][i] == height) {
        repeat++;
      } else {
        if (map[j][i] - height == 1 && L <= repeat) {
          height = map[j][i];
          repeat = 1;
        } else if (height - map[j][i] == 1) {
          int count = 0;
          for (int k = j; k < N; k++) {
            if (map[j][i] != map[k][i]) {
              isArrived = false;
              break;
            } else {
              count++;
              if (count == L) {
                height = map[j][i];
                repeat = 0;
                j = k;
                break;
              }
            }
          }
          if (count < L) {
            isArrived = false;
          }
        } else {
          isArrived = false;
          break;
        }
      }
    }
    if (isArrived) {
      result++;
    }
  }

  cout << result << "\n";
}