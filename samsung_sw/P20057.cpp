#include <iostream>

using namespace std;

void MoveUp(int amount, int i, int j);
void MoveDown(int amount, int i, int j);
void MoveLeft(int amount, int i, int j);
void MoveRight(int amount, int i, int j);

int N;
int m[500][500] = { 0 };
int d = 1, c = 0, length = 1;
int result = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> m[i][j];
    }
  }

  int i = N / 2, j = N / 2;
  while ((0 <= i && i < N) && (0 <= j && j < N)) {
    for (int t = 0; t < length; t++) {
      switch(d) {
        case 0:  // UP
          MoveUp(m[i - 1][j], i , j);
          i--;
          break;
        case 1:  // Left
          MoveLeft(m[i][j - 1], i , j);
          j--;
          break;
        case 2:  // DOWN
          MoveDown(m[i + 1][j], i , j);
          i++;
          break;
        case 3:  // RIGHT
          MoveRight(m[i][j + 1], i , j);
          j++;
          break;
      }
      cout << "R " << d << "\n";
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          cout << m[i][j] << " ";
        }
        cout << "\n";
      }
      cout << result << endl;
    }
    c++;
    length += c % 2 == 0 ? 1 : 0;
    d = (d + 1) % 4;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }

  cout << result << endl;
}

void MoveUp(int amount, int i, int j) {
  if (i - 1 < 0) {
    return;
  }

  int left = amount;
  int sand = amount * 5 / 100;
  if (i - 3 >= 0) {
    m[i - 3][j] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i - 2 >= 0 && j - 1 >= 0) {
    m[i - 2][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i - 2 >= 0 && j - 1 >= 0) {
    m[i - 2][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i - 1 >= 0 && j - 2 >= 0) {
    m[i - 1][j - 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i - 1 >= 0 && j - 1 >= 0) {
    m[i - 1][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i - 1 >= 0 && j + 1 < N) {
    m[i - 1][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i - 1 >= 0 && j + 2 < N) {
    m[i - 1][j + 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (j - 1 >= 0) {
    m[i][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (j + 1 < N) {
    m[i][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  if (i - 2 >= 0) {
    m[i - 2][j] += left;
  } else {
    result += left;
  }

  m[i - 1][j] = 0;
}

void MoveDown(int amount, int i, int j) {
  if (i + 1 >= N) {
    return;
  }

  int left = amount;

  int sand = amount * 5 / 100;
  if (i + 3 < N) {
    m[i + 3][j] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i + 2 < N && j - 1 >= 0) {
    m[i + 2][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i + 2 < N && j - 1 >= 0) {
    m[i + 2][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i + 1 < N && j - 2 >= 0) {
    m[i + 1][j - 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i + 1 < N && j - 1 >= 0) {
    m[i + 1][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i + 1 < N && j + 1 < N) {
    m[i + 1][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i + 1 < N && j + 2 < N) {
    m[i + 1][j + 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (j - 1 >= 0) {
    m[i][j - 1] += sand;
    cout << "C: " << m[i][j - 1] << endl;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (j + 1 < N) {
    m[i][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  if (i + 2 >= 0) {
    m[i + 2][j] += left;
  } else {
    result += left;
  }

  m[i + 1][j] = 0;
}

void MoveLeft(int amount, int i, int j) {
  if (j - 1 < 0) {
    return;
  }

  int left = amount;

  int sand = amount * 5 / 100;
  if (j - 3 >= 0) {
    m[i][j - 3] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i - 1 >= 0 && j - 2 >= 0) {
    m[i - 1][j - 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i + 1 < N && j - 2 >= 0) {
    m[i + 1][j - 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i - 2 >= 0 && j - 1 >= 0) {
    m[i - 2][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i - 1 >= 0 && j - 1 >= 0) {
    m[i - 1][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i + 1 < N && j - 1 >= 0) {
    m[i + 1][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i + 2 < N && j - 1 >= 0) {
    m[i + 2][j - 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (i - 1 >= 0) {
    m[i - 1][j] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (i + 1 < N) {
    m[i + 1][j] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  if (j - 2 >= 0) {
    m[i][j - 2] += left;
  } else {
    result += left;
  }

  m[i][j - 1] = 0;
}

void MoveRight(int amount, int i, int j) {
  if (j + 1 >= N) {
    return;
  }

  int left = amount;

  int sand = amount * 5 / 100;
  if (j + 3 < N) {
    m[i][j + 3] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i - 1 >= 0 && j + 2 < N) {
    m[i - 1][j + 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 10 / 100;
  if (i + 1 < N && j + 2 < N) {
    m[i + 1][j + 2] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i - 2 >= 0 && j + 1 < N) {
    m[i - 2][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i - 1 >= 0 && j + 1 < N) {
    m[i - 1][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 7 / 100;
  if (i + 1 < N && j + 1 < N) {
    m[i + 1][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 2 / 100;
  if (i + 2 < N && j + 1 < N) {
    m[i + 2][j + 1] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (i - 1 >= 0) {
    m[i - 1][j] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  sand = amount * 1 / 100;
  if (i + 1 < N) {
    m[i + 1][j] += sand;
  } else {
    result += sand;
  }
  left -= sand;

  if (j + 2 < N) {
    m[i][j + 2] += left;
  } else {
    result += left;
  }

  m[i][j + 1] = 0;
}