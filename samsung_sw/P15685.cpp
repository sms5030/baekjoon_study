#include <iostream>
#include <vector>

using namespace std;

void SetDragonCurve();

int N, x, y, d, g;

bool m[101][101] = { false };

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> d >> g;
    SetDragonCurve();
  }

  int result = 0;
  for (int i = 0; i < 100; i++) { 
    for (int j = 0; j < 100; j++) {
      if (m[i][j] && m[i + 1][j] && m[i][j + 1] && m[i + 1][j + 1]) {
        result++;
      }
    }
  }

  cout << result << endl;
}

void SetDragonCurve() {
  vector<int> v, dv;
  dv.push_back(d);
  m[y][x] = true;

  int cx = x;
  int cy = y;
  cx += d % 2 == 0 ? 1 - d : 0;
  cy += d % 2 == 1 ? d - 2 : 0;
  if (0 <= cx && cx <= 100 && 0 <= cy && cy <= 100) {
    v.push_back(cy * 101 + cx);
    m[cy][cx] = true;
  } else {
    return;
  }

  for (int turn = 0; turn < g; turn++) {
    int length = dv.size();
    cy = v[v.size() - 1] / 101;
    cx = v[v.size() - 1] % 101;
    for (int i = length - 1; i >= 0; i--) {
      int cd = (dv[i] + 1) % 4;
      dv.push_back(cd);

      cx += cd % 2 == 0 ? 1 - cd : 0;
      cy += cd % 2 == 1 ? cd - 2 : 0;

      if (0 <= cx && cx <= 100 && 0 <= cy && cy <= 100) {
        v.push_back(cy * 101 + cx);
        m[cy][cx] = true;
      } else {
        return;
      }
    }
  }
}