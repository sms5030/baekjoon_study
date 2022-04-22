#include <iostream>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return !(a.first < b.first);
    } else {
      return !(a.second < b.second);
    }
  }
};

int N, pos;
int m[21][21] = { 0 };

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> m[i][j];
      if (m[i][j] == 9) {
        pos = i * N + j;
      }
    }
  }

  int level = 2;
  int exp = 0;
  int time = 0;
  bool isFinished = false;
  while (isFinished == false) {
    isFinished = true;
    bool isVisited[21][21] = { false };
    priority_queue<pair<int, int>, vector<pair<int , int> >, cmp> pq;
  
    pq.push(make_pair(pos, 0));
    isVisited[pos / N][pos % N] = true;
    while(pq.empty() == false) {
      pair<int, int> cur = pq.top();
      pq.pop();
      int curI = cur.first / N;
      int curJ = cur.first % N;

      if (m[curI][curJ] != 9 && 0 < m[curI][curJ] && m[curI][curJ] < level) {
        m[pos / N][pos % N] = 0;
        pos = cur.first;
        time += cur.second;
        exp++;
        m[pos / N][pos % N] = 9;
        if (exp == level) {
          level++;
          exp = 0;
        }
        isFinished = false;
        break;
      }
      if (curI < N - 1 && isVisited[curI + 1][curJ] == false && m[curI + 1][curJ] <= level) {
        int nextPos = (curI + 1) * N + curJ;
        int nextDis = cur.second + 1;
        isVisited[curI + 1][curJ] = true;
        pq.push(make_pair(nextPos, nextDis));
      }

      if (curI > 0 && isVisited[curI - 1][curJ] == false && m[curI - 1][curJ] <= level) {
        int nextPos = (curI - 1) * N + curJ;
        int nextDis = cur.second + 1;
        isVisited[curI - 1][curJ] = true;
        pq.push(make_pair(nextPos, nextDis));
      }

      if (curJ < N - 1 && isVisited[curI][curJ + 1] == false && m[curI][curJ + 1] <= level) {
        int nextPos = curI * N + (curJ + 1);
        int nextDis = cur.second + 1;
        isVisited[curI][curJ + 1] = true;
        pq.push(make_pair(nextPos, nextDis));
      }

      if (curJ > 0 && isVisited[curI][curJ - 1] == false && m[curI][curJ - 1] <= level) {
        int nextPos = curI * N + (curJ - 1);
        int nextDis = cur.second + 1;
        isVisited[curI][curJ - 1] = true;
        pq.push(make_pair(nextPos, nextDis));
      }
    }
  }

  cout << time << endl;
}