#include <iostream>

using namespace std;

int N, M;
int m[501][501] = { 0 };

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }
  
  int maxVal = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M - 3; j++) {
      // oooo
      int sum = m[i][j] + m[i][j + 1] + m[i][j + 2] + m[i][j + 3];
      if (maxVal < sum) {
        maxVal = sum;
      }
    }
  }

  for (int i = 0; i < N - 3; i++) {
    for (int j = 0; j < M; j++) {
      // o
      // o
      // o
      // o
      int sum = m[i][j] + m[i + 1][j] + m[i + 2][j] + m[i + 3][j];
      if (maxVal < sum) {
        maxVal = sum;
      }
    }
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M - 1; j++) {
      // oo
      // oo
      int sum = m[i][j] + m[i + 1][j] + m[i][j + 1] + m[i + 1][j + 1];
      if (maxVal < sum) {
        maxVal = sum;
      }
    }
  }

  for (int i = 0; i < N - 2; i++) {
    for (int j = 0; j < M - 1; j++) {
      // oo
      // o
      // o
      int sum = m[i][j] + m[i + 1][j] + m[i + 2][j] + m[i][j + 1];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // oo
      //  o
      //  o
      sum = m[i][j + 1] + m[i + 1][j + 1] + m[i + 2][j + 1] + m[i][j];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // o
      // o
      // oo
      sum = m[i][j] + m[i + 1][j] + m[i + 2][j] + m[i + 2][j + 1];
      if (maxVal < sum) {
        maxVal = sum;
      }

      //  o
      //  o
      // oo
      sum = m[i][j + 1] + m[i + 1][j + 1] + m[i + 2][j + 1] + m[i + 2][j];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // o
      // oo
      //  o
      sum = m[i][j] + m[i + 1][j] + m[i + 1][j + 1] + m[i + 2][j + 1];
      if (maxVal < sum) {
        maxVal = sum;
      }

      //  o
      // oo
      // o
      sum = m[i][j + 1] + m[i + 1][j + 1] + m[i + 1][j] + m[i + 2][j];
      if (maxVal < sum) {
        maxVal = sum;
      }

      //  o
      // oo
      //  o
      sum = m[i][j + 1] + m[i + 1][j + 1] + m[i + 2][j + 1] + m[i + 1][j];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // o
      // oo
      // o
      sum = m[i][j] + m[i + 1][j] + m[i + 2][j] + m[i + 1][j + 1];
      if (maxVal < sum) {
        maxVal = sum;
      }
    }
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M - 2; j++) {
      // o
      // ooo
      int sum = m[i][j] + m[i + 1][j] + m[i + 1][j + 1] + m[i + 1][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      //   o
      // ooo
      sum = m[i][j + 2] + m[i + 1][j] + m[i + 1][j + 1] + m[i + 1][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // ooo
      // o
      sum = m[i + 1][j] + m[i][j] + m[i][j + 1] + m[i][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // ooo
      //   o
      sum = m[i + 1][j + 2] + m[i][j] + m[i][j + 1] + m[i][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      //  oo
      // oo
      sum = m[i + 1][j] + m[i][j + 1] + m[i + 1][j + 1] + m[i][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // oo
      //  oo
      sum = m[i][j] + m[i][j + 1] + m[i + 1][j + 1] + m[i + 1][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      //  o
      // ooo
      sum = m[i][j + 1] + m[i + 1][j] + m[i + 1][j + 1] + m[i + 1][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }

      // ooo
      //  o
      sum = m[i + 1][j + 1] + m[i][j] + m[i][j + 1] + m[i][j + 2];
      if (maxVal < sum) {
        maxVal = sum;
      }
    }
  }
  cout << maxVal << "\n";

  return 0;
}