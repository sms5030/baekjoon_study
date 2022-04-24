#include <iostream>
#include <vector>

using namespace std;

bool isFavorate(int value, int students[5]);

int N;
int location[21][21] = { 0 };
int students[401][5] = { 0 };
int main() {
  cin >> N;
  int length = N * N;
  for (int k = 1; k <= length; k++) {
    int num;
    cin >> num;
    students[num][0] = num;
    cin >> students[num][1] >> students[num][2] >> students[num][3] >> students[num][4];
    int max = -1;
    vector<int> maxList;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (location[i][j] != 0) {
          continue;
        }

        int favorate = 0;
        if (i - 1 >= 0 && isFavorate(location[i - 1][j], students[num])) {
          favorate++;
        }
        if (i + 1 < N && isFavorate(location[i + 1][j], students[num])) {
          favorate++;
        }
        if (j - 1 >= 0 && isFavorate(location[i][j - 1], students[num])) {
          favorate++;
        }
        if (j + 1 < N && isFavorate(location[i][j + 1], students[num])) {
          favorate++;
        }

        if (favorate > max) {
          max = favorate;
          maxList.clear();
          maxList.push_back(i * N + j);
        } else if (favorate == max) {
          maxList.push_back(i * N + j);
        }
      }
    }

    if (maxList.size() == 1) {
      int index = maxList[0];
      location[index / N][index % N] = students[num][0];
      continue;
    }

    int maxBlank = 0;
    vector<int> maxBlankList;
    for (int i = 0; i < maxList.size(); i++) {
      int index = maxList[i];
      int r = index / N;
      int c = index % N;
      
      int blank = 0;
      if (r - 1 >= 0 && location[r - 1][c] == 0) {
        blank++;
      }
      if (r + 1 < N && location[r + 1][c] == 0) {
        blank++;
      }
      if (c - 1 >= 0 && location[r][c - 1] == 0) {
        blank++;
      }
      if (c + 1 < N && location[r][c + 1] == 0) {
        blank++;
      }

      if (blank > maxBlank) {
        maxBlank = blank;
        maxBlankList.clear();
        maxBlankList.push_back(index);
      } else if (blank == maxBlank) {
        maxBlankList.push_back(index);
      }
    }


    int index = maxBlankList[0];
    location[index / N][index % N] = students[num][0];
  }

  int score = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int num = location[i][j];

      int favorate = 0;
      if (i - 1 >= 0 && isFavorate(location[i - 1][j], students[num])) {
        favorate++;
      }
      if (i + 1 < N && isFavorate(location[i + 1][j], students[num])) {
        favorate++;
      }
      if (j - 1 >= 0 && isFavorate(location[i][j - 1], students[num])) {
        favorate++;
      }
      if (j + 1 < N && isFavorate(location[i][j + 1], students[num])) {
        favorate++;
      }

      if (favorate == 1) {
        score += 1;
      } else if (favorate == 2) {
        score += 10;
      } else if (favorate == 3) {
        score += 100;
      } else if (favorate == 4) {
        score += 1000;
      }
    }
  }
  cout << score << endl;
}

bool isFavorate(int value, int students[5]) {
  for (int i = 1; i < 5; i++) {
    if (value == students[i]) {
      return true;
    }
  }
  return false;
}