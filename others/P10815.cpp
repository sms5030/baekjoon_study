 #include <iostream>
 #include <set>

using namespace std;

int N, M;
set<int> s;

 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     cin >> N;
     for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        s.insert(temp);
     }

     cin >> M;
     for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;

        cout << (s.find(temp) != s.end() ? 1 : 0) << " ";
     }

     return 0;
 }