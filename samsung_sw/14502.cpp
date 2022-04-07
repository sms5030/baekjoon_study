#include <iostream>
#include <vector>

using namespace std;

int FindArea(vector<vector<int> > v);

int N, M;
vector<vector<int> > v;
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    vector<int> tv;
    for (int j = 0; j < M; j++) {
      int temp;
      cin >> temp;
      tv.push_back(temp);
    }
    v.push_back(tv);
  }

  int maxValue = 0;
  int total = N * M;
  for(int i = 0; i < total; i++) {
    int i_n = i / M;
    int i_m = i % M;
    if (v[i_n][i_m] == 0) {
      v[i_n][i_m] = 1;
      for(int j = i + 1; j < total; j++) {
        int j_n = j / M;
        int j_m = j % M;
        if (v[j_n][j_m] == 0) {
          v[j_n][j_m] = 1;
          for (int k = j + 1; k < total; k++) {
            int k_n = k / M;
            int k_m = k % M;
            if (v[k_n][k_m] == 0) {
              v[k_n][k_m] = 1;
              int result = FindArea(v);
              if (result > maxValue) {
                maxValue = result;
              }
              v[k_n][k_m] = 0;
            }
          }
          v[j_n][j_m] = 0;
        }
      }
      v[i_n][i_m] = 0;
    }
  }

  cout << maxValue << endl;
}

int FindArea(vector<vector<int> > v) {
  bool isExand = true;
  bool isVisited[9][9] = { false };
  while (isExand) {
    isExand = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (v[i][j] == 2 && isVisited[i][j] == false) {
          isVisited[i][j] = true;
          if (i > 0 && v[i - 1][j] == 0) {
            v[i - 1][j] = 2;
            isExand = true;
          }
          if (i < N - 1 && v[i + 1][j] == 0) {
            v[i + 1][j] = 2;
            isExand = true;
          }
          if (j > 0 && v[i][j - 1] == 0) {
            v[i][j - 1] = 2;
            isExand = true;
          }
          if (j < M - 1 && v[i][j + 1] == 0) {
            v[i][j + 1] = 2;
            isExand = true;
          }
        }
      }
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (v[i][j] == 0) {
        count++;
      }
    }
  }
  return count;
}