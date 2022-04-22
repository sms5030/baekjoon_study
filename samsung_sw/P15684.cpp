#include <iostream>

using namespace std;

bool CheckLadder();

int N, M, H;
bool line[31][11] = { false };

int main() {
  cin >> N >> M >> H;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    line[a][b] = true;
  }

  if (CheckLadder()) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < (N - 1) * H; i++) {
    int c1 = (i % (N - 1)) + 1;
    int r1 = (i / (N - 1)) + 1;
    if (line[r1][c1] || (c1 > 1 && line[r1][c1 - 1]) || (c1 < N - 1 && line[r1][c1 + 1])) {
      continue;
    }
    line[r1][c1] = true;
    if (CheckLadder()) {
      cout << 1 << endl;
      return 0;
    }
    line[r1][c1] = false;
  }

  for (int i = 0; i < (N - 1) * H; i++) {
    int c1 = (i % (N - 1)) + 1;
    int r1 = (i / (N - 1)) + 1;
    if (line[r1][c1] || (c1 > 1 && line[r1][c1 - 1]) || (c1 < N - 1 && line[r1][c1 + 1])) {
      continue;
    }
    line[r1][c1] = true;
    for (int j = i; j < (N - 1) * H; j++) {
      int c2 = (j % (N - 1)) + 1;
      int r2 = (j / (N - 1)) + 1;
      if (line[r2][c2] || (c2 > 1 && line[r2][c2 - 1]) || (c2 < N - 1 && line[r2][c2 + 1])) {
        continue;
      }
      line[r2][c2] = true;
      if (CheckLadder()) {
        cout << 2 << endl;
        return 0;
      }
      line[r2][c2] = false;
    }
    line[r1][c1] = false;
  }

  for (int i = 0; i < (N - 1) * H; i++) {
    int c1 = (i % (N - 1)) + 1;
    int r1 = (i / (N - 1)) + 1;
    if (line[r1][c1] || (c1 > 1 && line[r1][c1 - 1]) || (c1 < N - 1 && line[r1][c1 + 1])) {
      continue;
    }

    line[r1][c1] = true;
    for (int j = i; j < (N - 1) * H; j++) {
      int c2 = (j % (N - 1)) + 1;
      int r2 = (j / (N - 1)) + 1;
      if (line[r2][c2] || (c2 > 1 && line[r2][c2 - 1]) || (c2 < N - 1 && line[r2][c2 + 1])) {
        continue;
      }
      line[r2][c2] = true;
      for (int k = j; k < (N -1) * H; k++) {
        int c3 = (k % (N - 1)) + 1;
        int r3 = (k / (N - 1)) + 1;
        if (line[r3][c3] || (c3 > 1 && line[r3][c3 - 1]) || (c3 < N - 1 && line[r3][c3 + 1])) {
        continue;
        }
        line[r3][c3] = true;
        if (CheckLadder()) {
          cout << 3 << endl;
          return 0;
        }
        line[r3][c3] = false;
      }
      line[r2][c2] = false;
    }
    line[r1][c1] = false;
  }

  cout << -1 << endl;
  return 0;
}

bool CheckLadder() {
  for (int i = 1; i < N; i++) {
    int pos = i;
    for (int j = 1; j <= H; j++) {
      if (pos < N && line[j][pos]) {
        pos++;
      } else if (pos > 1 && line[j][pos - 1]) {
        pos--;
      }
    }

    if (pos != i) {
      return false;
    }
  }

  return true;
}
