#include <iostream>
#include <vector>

using namespace std;

int GetNextI(int i, int speed, int direction);
int GetNextJ(int j, int speed, int direction);

int N, M, K;
vector<int> indexList, mList, sList, dList;

int main() {
  cin >> N >> M >> K;

  int r, c, im, is, id;
  for (int i = 0; i < M; i++) {
    cin >> r >> c >> im >> is >> id;
    indexList.push_back((r - 1) * N + (c - 1));
    mList.push_back(im);
    sList.push_back(is);
    dList.push_back(id);
  }

  for (int t = 0; t < K; t++) {
    int mergeCount[51][51] = { 0 };
    int m[51][51] = { 0 };
    int s[51][51] = { 0 };
    int d[51][51] = { 0 };

    int length = indexList.size();
    for (int i = 0; i < length; i++) {
      int curI = indexList[i] / N;
      int curJ = indexList[i] % N;
      int mass = mList[i];
      int direction = dList[i];
      int speed = sList[i];
      int nextI = GetNextI(curI, speed, direction);
      int nextJ = GetNextJ(curJ, speed, direction);

      m[nextI][nextJ] += mass;
      s[nextI][nextJ] += speed;
      if (mergeCount[nextI][nextJ] == 0) {
        d[nextI][nextJ] = direction;
      } else {
        d[nextI][nextJ] = d[nextI][nextJ] % 2 == direction % 2 ? d[nextI][nextJ] % 2 : -1;
      }
      mergeCount[nextI][nextJ]++;
    }

    indexList.clear();
    mList.clear();
    sList.clear();
    dList.clear();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (m[i][j] > 0) {
          if (mergeCount[i][j] > 1) {
            int fm = m[i][j] / 5;
            if (fm > 0) {
              int fs = s[i][j] / mergeCount[i][j];
              int fd = d[i][j] < 0 ? 1 : 0;
              for (int k = 0; k < 4; k++) {
                indexList.push_back(i * N + j);
                mList.push_back(fm);
                sList.push_back(fs);
                dList.push_back(fd + k * 2);
              }
            }
          } else {
            indexList.push_back(i * N + j);
            mList.push_back(m[i][j]);
            sList.push_back(s[i][j]);
            dList.push_back(d[i][j]);
          }
        }
      }
    }
  }

  int total = 0;
  int length = mList.size();
  for (int i = 0; i < length; i++) {
    total += mList[i];
  }

  cout << total << "\n";
  return 0;
}

int GetNextI(int i, int speed, int direction) {
  if (direction == 0 || direction == 1 || direction == 7) {
    return (N + i - (speed % N)) % N;
  } else if(direction == 3 || direction == 4 || direction == 5) {
    return (i + speed) % N;
  } else {
    return i;
  }
}

int GetNextJ(int j, int speed, int direction) {
  if (direction == 5 || direction == 6 || direction == 7) {
    return (N + j - (speed % N)) % N;
  } else if(direction == 1 || direction == 2 || direction == 3) {
    return (j + speed) % N;
  } else {
    return j;
  }
}