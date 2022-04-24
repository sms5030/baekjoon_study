#include <iostream>
#include <vector>

using namespace std;

void DiceGame(int turn, int horse, int result, vector<int> rootList, vector<int> posList);

int mapIndex[4][30] = {
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 100 },
  { 0, 1, 2, 3, 4, 5, 21, 22, 23, 29, 30, 31, 20, 100 },
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 24, 25, 29, 30, 31, 20, 100 },
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 26, 27, 28, 29, 30, 31, 20, 100 },
};

int map[4][30] = {
  { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0 },
  { 0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, 0 },
  { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40, 0 },
  { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, 0 },
};

int diceResult[10] = { 0 };
int maxResult = 0;

int main() {
  for (int i = 0; i < 10; i++) {
    cin >> diceResult[i];
  }

  vector<int> rootList;
  vector<int> posList;
  for (int i = 0; i < 4; i++) {
    rootList.push_back(0);
    posList.push_back(0);
  }

  for (int i = 0; i < 4; i++) {
    DiceGame(0, i, 0, rootList, posList);
  }

  cout << maxResult << endl;
}

void DiceGame(int turn, int horse, int result, vector<int> rootList, vector<int> posList) {
  int root = rootList[horse];
  int pos = posList[horse];
  
  int index = mapIndex[root][pos];
  if (index == 100) {
    return;
  }
  
  pos += diceResult[turn];
  if (root == 0 && pos >= 21) {
    pos = 21;
  } else if (root == 1 && pos >= 13) {
    pos = 13;
  } else if (root == 2 && pos >= 17) {
    pos = 17;
  } else if (root == 3 && pos >= 23) {
    pos = 23;
  }

  index = mapIndex[root][pos];
  for (int i = 0; i < 4; i++) {
    int hRoot = rootList[i];
    int hPos = posList[i];
    int hIndex = mapIndex[hRoot][hPos];
    if (hIndex < 100 && index == hIndex)
    {
      return;
    }
  }

  if (root == 0) {
    if (pos == 5) {
      root = 1;
    } else if (pos == 10) {
      root = 2;
    } else if (pos == 15) {
      root = 3;
    }
  }

  result += map[root][pos];

  rootList[horse] = root;
  posList[horse] = pos;

  if (turn == 9) {
    if (result > maxResult) {
      maxResult = result;
    }
    return;
  } else {
    for (int i = 0; i < 4; i++) {
      DiceGame(turn + 1, i, result, rootList, posList);
    }
  }
}