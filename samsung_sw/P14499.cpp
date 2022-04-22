#include <iostream>

using namespace std;

void MoveDice(int move);
void ChangePos(int move);

int N, M, x, y, k;
int m[21][21] = { 0 };
int top = 1, bottom = 6, east = 3, west = 4, north = 2, south = 5;
int dice[7] = { 0 };

int main() {
  cin >> N >> M >> x >> y >> k;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < k; i++) {
    int move;
    cin >> move;
    
    MoveDice(move);
  }

  return 0;
}

void MoveDice(int move) {
  if (move == 1) {  // East
    if (y >= M - 1) {
      return;
    }
    ChangePos(move);
    y++;
  } else if (move == 2) {  // West
    if (y < 1) {
      return;
    }
    ChangePos(move);
    y--;
  } else if (move == 3) {  // North
    if (x < 1) {
      return;
    }
    ChangePos(move);
    x--;
  } else if (move == 4) {  // South
    if (x >= N - 1) {
      return;
    }
    ChangePos(move);
    x++;
  } else {
    return;
  }

  if (m[x][y] == 0) {
    m[x][y] = dice[bottom];
  } else {
    dice[bottom] = m[x][y];
    m[x][y] = 0;
    
  }
  cout << dice[top] << endl;
}

void ChangePos(int move) {
  int temp;
  switch(move) {
    case 1:  // East
      temp = bottom;
      bottom = east;
      top = 7 - bottom;
      west = temp;
      east = 7 - west;
      break;
    case 2:  // West
      temp = bottom;
      bottom = west;
      top = 7 - bottom;
      east = temp;
      west = 7 - east;
      break;
    case 3:  // North
      temp = bottom;
      bottom = north;
      top = 7 - bottom;
      south = temp;
      north = 7 - south;
      break;
    case 4:  // South
      temp = bottom;
      bottom = south;
      top = 7 - bottom;
      north = temp;
      south = 7 - north;
      break;
  }
}