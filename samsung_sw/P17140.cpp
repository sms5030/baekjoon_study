#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CalcR(int row);
void CalcC(int col);
bool Compare(pair<int, int> a, pair<int, int> b);

int N = 3, M = 3, R, C, K;
int m[101][101] = { 0 };
vector<pair<int, int> > v;

int main() {
  cin >> R >> C >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }

  int turn;
  for (turn = 0; turn < 101; turn++) {
    if (m[R - 1][C - 1] == K) {
      break;
    }

    if (N >= M) {
      for (int i = 0; i < N; i++) {
        CalcR(i);
      }
    } else {
      for (int i = 0; i < M; i++) {
        CalcC(i);
      }
    }
  }

  cout << (turn <= 100 ? turn : -1) << "\n";
  return 0;
}

void CalcR(int row) {
  int count[101] = { 0 };

  for (int i = 0; i < M; i++) {
    count[m[row][i]]++;
  }

  vector<pair<int, int> > v;
  for (int i = 1; i < 101; i++) {
    if (count[i] > 0) {
      v.push_back(make_pair(i, count[i]));
    }
  }

  sort(v.begin(), v.end(), Compare);
  int length = v.size();
  int clearIndex = length * 2;
  for (int i = 0; i < length; i++) {
    if (2 * i >= 100) {
      break;
    }
    m[row][2 * i] = v[i].first;
    if (2 * i + 1 >= 100) {
      break;
    }
    m[row][2 * i + 1] = v[i].second;
  }
  
  for (int i = length * 2; i < 101; i++) {
    m[row][i] = 0;
  }

  length = length * 2 > 100 ? 100 : length * 2;

  if (M < length) {
    M = length;
  }
}

void CalcC(int col) {
  int count[101] = { 0 };
  for (int i = 0; i < N; i++) {
    count[m[i][col]]++;
  }

  vector<pair<int, int> > v;
  for (int i = 1; i < 101; i++) {
    if (count[i] > 0) {
      v.push_back(make_pair(i, count[i]));
    }
  }

  sort(v.begin(), v.end(), Compare);
  int length = v.size();
  int clearIndex = length * 2;
  for (int i = 0; i < length; i++) {
    if (2 * i >= 100) {
      break;
    }
    m[2 * i][col] = v[i].first;
    if (2 * i + 1 >= 100) {
      break;
    }
    m[2 * i + 1][col] = v[i].second;
  }
  
  for (int i = length * 2; i < 101; i++) {
    m[i][col] = 0;
  }

  length = length * 2 > 100 ? 100 : length * 2;

  if (N < length) {
    N = length;
  }
}

bool Compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}