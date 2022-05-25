#include <iostream>
#include <string>

using namespace std;

int states[10][2] = {
  {1, 2},  // 0
  {9, 3},  // 1
  {4, 9},  // 2
  {1, 2},  // 3 (F)
  {5, 9},  // 4
  {5, 6},  // 5
  {1, 7},  // 6 (F)
  {8, 7},  // 7 (F)
  {5, 3},  // 8
  {9, 9},  // 9
};

int main() {
  int T;
  string str;

  cin >> T;
  for (int turn = 0; turn < T; turn++) {
    cin >> str;

    int curState = 0;
    int strLen = str.size();
    for (int i = 0; i < strLen; i++) {
      int transition = str[i] - '0';
      int prevState = curState;
      curState = states[curState][transition];

      if (curState == 9) {
        break;
      }
    }
    if (curState == 3 || curState == 6 || curState == 7) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}