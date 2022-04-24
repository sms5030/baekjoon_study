#include <iostream>

using namespace std;

void SpreadDust();
void CleanDust();

int R, C, T;
int upRow = -1, downRow = -1;
int map[50][50] = { 0 };

int main() {
  cin >> R >> C >> T;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> map[i][j];
      if (j == 0 && map[i][j] == -1 && upRow == -1) {
        upRow = i;
        downRow = i + 1;
      }
    }
  }


  for (int i = 0; i < T; i++) {
    SpreadDust();
    CleanDust();
  }

  int score = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (map[i][j] > 0) {
        score += map[i][j];
      }
    }
  }
  cout << score << endl;
}

void SpreadDust() {
  int newMap[50][50] = { 0 };
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (map[i][j] == -1) {
        newMap[i][j] = -1;
        continue;
      }

      int cur = map[i][j];
      if (map[i][j] > 0) {
        int power = map[i][j] / 5;
        if (i - 1 >= 0 && map[i - 1][j] != -1) {
          cur -= power;
        }
        if (i + 1 < R && map[i + 1][j] != -1) {
          cur -= power;
        }
        if (j - 1 >= 0 && map[i][j - 1] != -1) {
          cur -= power;
        }
        if (j + 1 < C && map[i][j + 1] != -1) {
          cur -= power;
        }
      }

      if (i - 1 >= 0 && map[i - 1][j] > 0) {
        cur += (map[i - 1][j] / 5);
      }
      if (i + 1 < R && map[i + 1][j] > 0) {
        cur += (map[i + 1][j] / 5);
      }
      if (j - 1 >= 0 && map[i][j - 1] > 0) {
        cur += (map[i][j - 1] / 5);
      }
      if (j + 1 < C && map[i][j + 1] > 0) {
        cur += (map[i][j + 1] / 5);
      }

      newMap[i][j] = cur;
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      map[i][j] =newMap[i][j];
    }
  }
}

void CleanDust() {
  for (int i = upRow - 1; i >= 1; i--) {
    map[i][0] = map[i - 1][0];
  }
  for (int i = 0; i < C - 1; i++) {
    map[0][i] = map[0][i + 1];
  }
  for (int i = 0; i < upRow; i++) { 
    map[i][C - 1] = map[i + 1][C -1];
  }
  for (int i = C - 1; i >= 2; i--) { 
    map[upRow][i] = map[upRow][i - 1];
  }
  map[upRow][1] = 0;


  for (int i = downRow + 1; i < R - 1; i++) {
    map[i][0] = map[i + 1][0];
  }
  for (int i = 0; i < C - 1; i++) {
    map[R - 1][i] = map[R - 1][i + 1];
  }
  for (int i = R - 1; i > downRow; i--) { 
    map[i][C - 1] = map[i - 1][C -1];
  }
  for (int i = C - 1; i >= 2; i--) { 
    map[downRow][i] = map[downRow][i - 1];
  }
  map[downRow][1] = 0;
}