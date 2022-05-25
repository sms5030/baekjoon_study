#include <iostream>

using namespace std;

char top[3][3] = { 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
char bottom[3][3] = { 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
char front[3][3] = { 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
char back[3][3] = { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
char leftSide[3][3] = { 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g' };
char rightSide[3][3] = { 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };

int main() {

}

void CW(char space[3][3]) {
  char newSpace[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      newSpace[j][2 - i] = space[i][j];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      space[i][j] = newSpace[i][j];
    }
  }
}

void CCW(char space[3][3]) {
  char newSpace[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      newSpace[2 - j][i] = space[i][j];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      space[i][j] = newSpace[i][j];
    }
  }
}

void TopMove(bool isCW) {
  char temp[3];
  for (int i = 0; i < 3; i++) {
    temp[i] = front[0][i];
  }

  if (isCW) {
    for (int i = 0; i < 3; i++) {
      front[0][i] = leftSide[0][i];
      leftSide[0][i] = back[0][i];
      back[0][i] = rightSide[0][i];
      rightSide[0][i] = temp[i];
    }
  } else {
    for (int i = 0; i < 3; i++) {
      front[0][i] = rightSide[0][i];
      rightSide[0][i] = back[0][i];
      back[0][i] = leftSide[0][i];
      leftSide[0][i] = temp[i];
    }
  }
}

void BottomMove(bool isCW) {
  char temp[3];
  for (int i = 0; i < 3; i++) {
    temp[i] = front[2][i];
  }

  if (isCW) {
    for (int i = 0; i < 3; i++) {
      front[2][i] = rightSide[2][i];
      rightSide[2][i] = back[2][i];
      back[2][i] = leftSide[2][i];
      leftSide[2][i] = temp[i];
    }
  } else {
    for (int i = 0; i < 3; i++) {
      front[2][i] = leftSide[2][i];
      leftSide[2][i] = back[2][i];
      back[2][i] = rightSide[2][i];
      rightSide[2][i] = temp[i];
    }
  }
}

void FrontMove(bool isCW) {
  char temp[3];
  for (int i = 0; i < 3; i++) {
    temp[i] = top[2][i];
  }

  if (isCW) {
    for (int i = 0; i < 3; i++) {
      top[2][i] = leftSide[2 - i][2];
      leftSide[i][2] = bottom[2][2 - i];
      bottom[2][i] = rightSide[2 - i][0];
      rightSide[i][0] = temp[2 - i];
    }
  } else {
    for (int i = 0; i < 3; i++) {
      front[0][i] = rightSide[0][i];
      rightSide[0][i] = back[0][i];
      back[0][i] = leftSide[0][i];
      leftSide[0][i] = temp[i];
    }
  }
}
