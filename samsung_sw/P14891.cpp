#include <iostream>
#include <string>

using namespace std;

void ChangeGeer(int gn, int d);
void ChangeGeerPos(int gn, int d);

string geer[4];
int pos[4] = { 0 };
int N, gn, d;

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> geer[i];
  }

  cin >> N;
  for (int turn = 0; turn < N; turn++) {
    cin >> gn >> d;
    ChangeGeer(gn - 1, d);
  }

  int result = 0;
  int multiplier = 1;
  for (int i = 0; i < 4; i++) {
    result += (geer[i][pos[i]] - '0') * multiplier;
    multiplier *= 2;
  }
  cout << result << endl;

  return 0;
}

void ChangeGeer(int gn, int d) {
  int changedType[4] = { 0 };
  changedType[gn] = d;

  int curDirect = d;
  for(int i = gn - 1; i >= 0; i--) {
    int centerGeerPos = pos[i + 1];
    int centerAttachedType = geer[i + 1][(8 + centerGeerPos - 2) % 8];

    int leftGeerPos = pos[i];
    int leftAttachedType = geer[i][(leftGeerPos + 2) % 8];

    if (centerAttachedType == leftAttachedType) {
      break;
    }

    curDirect *= -1;
    changedType[i] = curDirect;
  }

  curDirect = d;
  for(int i = gn + 1; i < 4; i++) {
    int centerGeerPos = pos[i - 1];
    int centerAttachedType = geer[i - 1][(centerGeerPos + 2) % 8];

    int rightGeerPos = pos[i];
    int rightAttachedType = geer[i][(8 + rightGeerPos - 2) % 8];

    if (centerAttachedType == rightAttachedType) {
      break;
    }

    curDirect *= -1;
    changedType[i] = curDirect;
  }

  for (int i = 0; i < 4; i++) {
    if (changedType[i] != 0) {
      ChangeGeerPos(i, changedType[i]);
    }
  }

  return;
}

void ChangeGeerPos(int gn, int d) {
  if (d > 0) {
    pos[gn] = (8 + pos[gn] - 1) % 8;
  } else {
    pos[gn] = (pos[gn] + 1) % 8;
  }
}