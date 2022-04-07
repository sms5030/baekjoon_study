#include <iostream>

using namespace std;

int A, B, C;

int main() {
  cin >> A >> B >> C;

  int carry = 0;
  B = B + (C % 60);
  if (B >= 60) {
    carry = 1;
    B %= 60;
  }
  A = (A + (C / 60) + carry) % 24;

  cout << A << " " << B;
}