#include <iostream>
#include <set>

using namespace std;
int a, b, temp;
set<int> A, B;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> temp;
        A.insert(temp);
    }

    for (int i = 0; i < b; i++) {
        cin >> temp;
        B.insert(temp);
    }

    int intersectionCount = 0;
    if (a < b) {
        set<int>::iterator iter;
        for (iter = A.begin(); iter != A.end(); iter++) {
            if (B.find(*iter) != B.end()) {
                intersectionCount++;
            }
        }
    } else {
        set<int>::iterator iter;
        for (iter = B.begin(); iter != B.end(); iter++) {
            if (A.find(*iter) != A.end()) {
                intersectionCount++;
            }
        }
    }

    cout << a + b - (intersectionCount + intersectionCount) << endl;

    return 0;
}