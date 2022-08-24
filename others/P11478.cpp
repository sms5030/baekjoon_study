#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;
string str;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    int strLen = str.size();
    for (int i = 0; i < strLen; i++) {
        int jMax = strLen - i;
        for (int j = 0; j < jMax; j++) {
            s.insert(str.substr(j, i + 1));
        }
    }
    cout << s.size() << endl;
    return 0;
}