#include <iostream>
#include <vector>

using namespace std;

void FindUnion(int i, int j);

int N, L, R;
int m[51][51] = { 0 };

vector<int> indice;
bool isVisited[51][51] = { false };

int main() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> m[i][j];
    }
  }

  int turn = 0;
  bool isMove = true;
  while(isMove) {
    isMove = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
       isVisited[i][j] = false;
      }
    }
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (isVisited[i][j] == false) {
          indice.clear();
          FindUnion(i, j);
          int indiceCount = indice.size();
          if (indiceCount > 1) {
            int total = 0;
            for (int k = 0; k < indiceCount; k++) {
              int index = indice[k];
              total += m[index / N][index % N];
            }
            total /= indiceCount;
            for (int k = 0; k < indiceCount; k++) {
              int index = indice[k];
              m[index / N][index % N] = total;
            }
            isMove = true;
          }
        }
      }
    }

    if (isMove) {
      turn++;
    }
  }

  cout << turn << "\n";
}

void FindUnion(int i, int j) {
  isVisited[i][j] = true;
  indice.push_back(i * N + j);

  if (i - 1 >= 0 && isVisited[i - 1][j] == false) {
    int diff = m[i - 1][j] > m[i][j] ? m[i - 1][j] - m[i][j] : m[i][j] - m[i - 1][j];
    if (L <= diff && diff <= R) {
      FindUnion(i - 1, j);
    }
  }

  if (i + 1 < N && isVisited[i + 1][j] == false) {
    int diff = m[i + 1][j] > m[i][j] ? m[i + 1][j] - m[i][j] : m[i][j] - m[i + 1][j];
    if (L <= diff && diff <= R) {
      FindUnion(i + 1, j);
    }
  }

  if (j - 1 >= 0 && isVisited[i][j - 1] == false) {
    int diff = m[i][j - 1] > m[i][j] ? m[i][j - 1] - m[i][j] : m[i][j] - m[i][j - 1];
    if (L <= diff && diff <= R) {
      FindUnion(i, j - 1);
    }
  }

  if (j + 1 < N && isVisited[i][j + 1] == false) {
    int diff = m[i][j + 1] > m[i][j] ? m[i][j + 1] - m[i][j] : m[i][j] - m[i][j + 1];
    if (L <= diff && diff <= R) {
      FindUnion(i, j + 1);
    }
  }
}