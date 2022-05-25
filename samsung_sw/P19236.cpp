#include <iostream>

using namespace std;

void MoveShark(int result);
void UpdateIndice();
void MoveFishes();
bool CheckDirection(int index, int direction);
void PrintM();
void PrintD();
void PrintIndice();

int m[4][4] = { 0 };
int d[4][4] = { 0 };
int indice[17] = { 0 };

int maxResult = 0;

int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> m[i][j] >> d[i][j];
    }
  }
  UpdateIndice();

  int result = m[0][0];
  m[0][0] = 0;
  MoveShark(result);

  cout << maxResult << endl;
  return 0;
}

void UpdateIndice() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      indice[m[i][j]] = i * 4 + j;
    }
  }
}

void MoveShark(int result) {
  int om[4][4] = { 0 };
  int od[4][4] = { 0 };
  int oindice[17] = { 0 };
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      om[i][j] = m[i][j];
      od[i][j] = d[i][j];
    }
  }
  for (int i = 0; i < 17; i++) {
    oindice[i] = indice[i];
  }

  MoveFishes();

  PrintM();

  int index = indice[0];
  int direction = d[index / 4][index %4];
  int di = 0, dj = 0;
  switch(direction) {
    case 1:
      di -= 1;
      break;
    case 2:
      di -= 1;
      dj -= 1;
      break;
    case 3:
      dj -= 1;
      break;
    case 4:
      di += 1;
      dj -= 1;
      break;
    case 5:
      di += 1;
      break;
    case 6:
      di += 1;
      dj += 1;
      break;
    case 7:
      dj += 1;
      break;
    case 8:
      di -= 1;
      dj += 1;
      break;
  }

  int count = 0;
  for (int i = 1; i < 4; i++) {
    int nextI = (index / 4) + (di * i);
    int nextJ = (index % 4) + (dj * i);
    if (0 <= nextI && nextI <= 3 && 0 <= nextI && nextJ <= 3) {
      if (m[nextI][nextJ] > 0) {
        result += m[nextI][nextJ];
      }
      m[index / 4][index % 4] = -1;
      m[nextI][nextJ] = 0;
      d[index / 4][index % 4] = -1;
      UpdateIndice();
      MoveShark(result);
      count++;
    }
  }

  if (count == 0) {
    if (result > maxResult) {
      maxResult = result;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] = om[i][j];
      d[i][j] = od[i][j];
    }
  }
  for (int i = 0; i < 17; i++) {
    indice[i] = oindice[i];
  }
}

void MoveFishes() {
  for (int i = 1; i < 17; i++) {
    int index = indice[i];
    if (index == 0 || index == -1) {
      continue;
    }
    int direction = d[index / 4][index % 4];
    for (int j = 0; j < 8; j++) {
      if (CheckDirection(index, (direction - 1 + j) % 8 + 1)) {
        UpdateIndice();
        break;
      }
    }
  }
}

bool CheckDirection(int index, int direction) {
  int curI = index / 4;
  int curJ = index % 4;
  int nextI = curI;
  int nextJ = curJ;
  switch(direction) {
    case 1:
      nextI -= 1;
      break;
    case 2:
      nextI -= 1;
      nextJ -= 1;
      break;
    case 3:
      nextJ -= 1;
      break;
    case 4:
      nextI += 1;
      nextJ -= 1;
      break;
    case 5:
      nextI += 1;
      break;
    case 6:
      nextI += 1;
      nextJ += 1;
      break;
    case 7:
      nextJ += 1;
      break;
    case 8:
      nextI -= 1;
      nextJ += 1;
      break;
  }

  if (0 <= nextI && nextI <= 3 && 0 <= nextJ && nextJ <= 3 && m[nextI][nextJ] != 0) {
    d[curI][curJ] = direction;

    int temp;
    temp = m[curI][curJ];
    m[curI][curJ] = m[nextI][nextJ];
    m[nextI][nextJ] = temp;

    temp = d[curI][curJ];
    d[curI][curJ] = d[nextI][nextJ];
    d[nextI][nextJ] = temp;
    return true;
  }

  return false;
}

void PrintM() {
  cout << "M\n";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
}

void PrintD() {
  cout << "D\n";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << d[i][j] << " ";
    }
    cout << "\n";
  }
}

void PrintIndice() {
  cout << "Indice\n";
  for (int i = 0; i < 17; i++) {
    cout << indice[i] << " ";
  }
  cout << "\n";
}