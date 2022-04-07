#include <iostream>

using namespace std;

int A, B, C;

int main() {
  cin >> A >> B >> C;

  if (A == B && B == C) {
    cout << 10000 + A * 1000 << endl;
  } else if (A == B) {
    cout << 1000 + A * 100 << endl;
  } else if (B == C) {
    cout << 1000 + B * 100 << endl;
  } else if (C == A) {
    cout << 1000 + C * 100 << endl;
  } else {
    int max = A > B ? (A > C ? A : C) : (B > C ? B : C);
    cout << max * 100 << endl;
  }
  return 0;
}