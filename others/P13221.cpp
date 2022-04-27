#include <iostream>

using namespace std;

int x, y, N, tx, ty, minDistance = 1000000, minX = -1, minY = -1;

int main() {
  cin >> x >> y >> N;
  for (int i = 0; i < N; i++) {
    cin >> tx >> ty;
    int distance = (tx > x ? tx - x : x - tx) + (ty > y ? ty - y : y - ty);
    if (minDistance > distance) {
      minDistance = distance;
      minX = tx;
      minY = ty;
    }
  }
  cout << minX << " " << minY << "\n";

  return 0;
}
