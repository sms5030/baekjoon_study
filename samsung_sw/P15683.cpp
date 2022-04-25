#include <iostream>
#include <vector>

using namespace std;

void FindMinArea(int N, int cctvCount);
void GetMinArea();
void Up(int nm[10][10], int row, int col);
void Down(int nm[10][10], int row, int col);
void Left(int nm[10][10], int row, int col);
void Right(int nm[10][10], int row, int col);

int N, M;
int m[10][10] = { 0 };
vector<int> cctvType;
vector<int> cctvIndex;
vector<int> cctvDirection;
int minArea = 0;

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
      if (1 <= m[i][j] && m[i][j] <= 5) {
        cctvType.push_back(m[i][j]);
        cctvIndex.push_back(i * M + j);
        cctvDirection.push_back(1);
      }
    }
  }

  int cctvCount = cctvType.size();
  minArea = N * M + 1;
  FindMinArea(0, cctvCount);

  cout << minArea << "\n";
}

void FindMinArea(int N, int cctvCount) {
  if (N == cctvCount) {
    GetMinArea();
    return;
  }

  int type = cctvType[N];
  if (type == 5) {
    cctvDirection[N] = 0;
    FindMinArea(N + 1, cctvCount);
  } else if (type == 2) {
    for (int i = 0; i < 2; i++) {
      cctvDirection[N] = i;
      FindMinArea(N + 1, cctvCount);
    }
  } else {
    for (int i = 0; i < 4; i++) {
      cctvDirection[N] = i;
      FindMinArea(N + 1, cctvCount);
    }
  }
}

void GetMinArea() {
  int cctvCount = cctvType.size();
  int nm[10][10] = { 0 };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      nm[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < cctvCount; i++) {
    int type = cctvType[i];
    int index = cctvIndex[i];
    int direction = cctvDirection[i];
    if (type == 1) {
      if (direction == 0) {
        Right(nm, index / M, index % M);
      } if (direction == 1) {
        Up(nm, index / M, index % M);
      } if (direction == 2) {
        Left(nm, index / M, index % M);
      } if (direction == 3) {
        Down(nm, index / M, index % M);
      }
    } else if (type == 2) {
      if (direction == 0) {
        Right(nm, index / M, index % M);
        Left(nm, index / M, index % M);
      } if (direction == 1) {
        Up(nm, index / M, index % M);
        Down(nm, index / M, index % M);
      }
    }  else if (type == 3) {
      if (direction == 0) {
        Up(nm, index / M, index % M);
        Right(nm, index / M, index % M);
      } if (direction == 1) {
        Up(nm, index / M, index % M);
        Left(nm, index / M, index % M);
      } if (direction == 2) {
        Left(nm, index / M, index % M);
        Down(nm, index / M, index % M);
      } if (direction == 3) {
        Down(nm, index / M, index % M);
        Right(nm, index / M, index % M);
      }
    }  else if (type == 4) {
      if (direction == 0) {
        Up(nm, index / M, index % M);
        Right(nm, index / M, index % M);
        Left(nm, index / M, index % M);
      } if (direction == 1) {
        Up(nm, index / M, index % M);
        Left(nm, index / M, index % M);
        Down(nm, index / M, index % M);
      } if (direction == 2) {
        Left(nm, index / M, index % M);
        Down(nm, index / M, index % M);
        Right(nm, index / M, index % M);
      } if (direction == 3) {
        Down(nm, index / M, index % M);
        Right(nm, index / M, index % M);
        Up(nm, index / M, index % M);
      }
    }  else if (type == 5) {
      Right(nm, index / M, index % M);
      Left(nm, index / M, index % M);
      Up(nm, index / M, index % M);
      Down(nm, index / M, index % M);
    }
    
  }

  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (nm[i][j] == 0) {
        result++;
      }
    }
  }

  if (result < minArea) {
    minArea = result;
  }
}

void Up(int nm[10][10], int row, int col) {
  for (int i = row - 1; i >= 0; i--) {
    if (nm[i][col] == 6) {
      break;
    } else if (1 <= nm[i][col] && nm[i][col] <= 5) {
      continue;
    } else {
      nm[i][col] = 9;
    }
  }
}

void Down(int nm[10][10], int row, int col) {
  for (int i = row + 1; i < N; i++) {
    if (nm[i][col] == 6) {
      break;
    } else if (1 <= nm[i][col] && nm[i][col] <= 5) {
      continue;
    } else {
      nm[i][col] = 9;
    }
  }
}

void Left(int nm[10][10], int row, int col) {
  for (int i = col - 1; i >= 0; i--) {
    if (nm[row][i] == 6) {
      break;
    } else if (1 <= nm[row][i] && nm[row][i] <= 5) {
      continue;
    } else {
      nm[row][i] = 9;
    }
  }
}

void Right(int nm[10][10], int row, int col) {
  for (int i = col + 1; i < M; i++) {
    if (nm[row][i] == 6) {
      break;
    } else if (1 <= nm[row][i] && nm[row][i] <= 5) {
      continue;
    } else {
      nm[row][i] = 9;
    }
  }
}