#include <iostream>

using namespace std;

void MoveWest();
void MoveEast();
void MoveNorth();
void MoveSouth();
int GetScore(int i, int j);

int top = 1, bottom = 6, west = 4, east = 3, north = 2, south = 5;
int N, M, K;
int m[25][25] = { 0 };
bool isVisited[25][25] = { false };
int di = 0, dj = 0, dd = 0;

int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }

  int totalSum = 0;
  for (int k = 0; k < K; k++) {
    if ((dd == 0 && dj + 1 >= M)
      || (dd == 1 && di + 1 >= N)
      || (dd == 2 && dj - 1 < 0)
      || (dd == 3 && di - 1 < 0)) {
      dd = (dd + 2) % 4;
    }

    switch(dd) {
      case 0:  // East
        MoveEast();
        dj++;
        break;
      case 1:  // South
        MoveSouth();
        di++;
        break;
      case 2:  // West
        MoveWest();
        dj--;
        break;
      case 3:  // North
        MoveNorth();
        di--;
        break;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        isVisited[i][j] = false;
      }
    }
    totalSum += GetScore(di, dj);

    if (bottom > m[di][dj]) {
      dd = (dd + 1) % 4;
    } else if (bottom < m[di][dj]) {
      dd = (dd + 3) % 4;
    }
  }

  cout << totalSum << "\n";
  return 0;
}

void MoveWest() {
  int temp = bottom;
  bottom = west;
  top = 7 - bottom;
  east = temp;
  west = 7 - east;
}

void MoveEast() {
  int temp = bottom;
  bottom = east;
  top = 7 - bottom;
  west = temp;
  east = 7 - west;
}

void MoveNorth() {
  int temp = bottom;
  bottom = north;
  top = 7 - bottom;
  south = temp;
  north = 7 - south;
}

void MoveSouth() {
  int temp = bottom;
  bottom = south;
  top = 7 - bottom;
  north = temp;
  south = 7 - north;
}

int GetScore(int i, int j) {
  int sum = m[i][j];
  isVisited[i][j] = true;

  if (i - 1 >= 0 && isVisited[i - 1][j] == false && m[i][j] == m[i - 1][j]) {
    sum += GetScore(i - 1, j);
  }

  if (i + 1 < N && isVisited[i + 1][j] == false && m[i][j] == m[i + 1][j]) {
    sum += GetScore(i + 1, j);
  }

  if (j - 1 >= 0 && isVisited[i][j - 1] == false && m[i][j] == m[i][j - 1]) {
    sum += GetScore(i, j - 1);
  }

  if (j + 1 < M && isVisited[i][j + 1] == false && m[i][j] == m[i][j + 1]) {
    sum += GetScore(i, j + 1);
  }
  return sum;
} 