 #include <iostream>
 #include <string>
 #include <set>

using namespace std;

int N, M;
set<string> s;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        s.insert(temp);
    }

    int containCount = 0;
    for (int i = 0; i < M; i++) {
        string temp;
        cin >> temp;
        if (s.find(temp) != s.end()) {
            containCount++;
        }
    }

    cout << containCount << endl;
    return 0;
}