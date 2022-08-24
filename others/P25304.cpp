#include <iostream>

using namespace std;

int X, N, a, b, total = 0;

int main() {
    cin >> X >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        total += (a * b);
    }

    cout << (X == total ? "Yes" : "No") << endl;
    return 0;
}