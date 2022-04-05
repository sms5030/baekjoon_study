#include <iostream>

using namespace std;

int N, M, r, c, d;
int map[51][51] = { 0 };

int FindCleanArea(int count);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  cin >> r >> c >> d;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  map[r][c] = 2;
  cout << 1 + FindCleanArea(0);
}

int FindCleanArea(int count) {
  int nr = 0, nc = 0, nd = 0;
  if (count == 4) {
    switch(d) {
      case 0:
        nr = r + 1;
        nc = c;
        break;
      case 1:
        nr = r;
        nc = c - 1;
        break;
      case 2:
        nr = r - 1;
        nc = c;
        break;
      case 3:
        nr = r;
        nc = c + 1;
        break;
    }

    if (map[nr][nc] == 0) {
      r = nr;
      c = nc;
      map[r][c] = 2;
      return 1 + FindCleanArea(0);
    } else if (map[nr][nc] == 2) {
      r = nr;
      c = nc;
      return FindCleanArea(0);
    }
    else {
      return 0;
    }
  }

  switch(d) {
    case 0:  // N -> W
      nr = r;
      nc = c - 1;
      nd = 3;
      break;
    case 1:  // E -> N
      nr = r - 1;
      nc = c;
      nd = 0;
      break;
    case 2:  // S -> E
      nr = r;
      nc = c + 1;
      nd = 1;
      break;
    case 3:  // W -> S
      nr = r + 1;
      nc = c;
      nd = 2;
      break;
  }

  d = nd;
  if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0) {
    r = nr;
    c = nc;
    map[r][c] = 2;
    return 1 + FindCleanArea(0);
  } else {
    return FindCleanArea(count + 1);
  }
}