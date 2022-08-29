#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[200000] = { false };
queue<pair<int, int> > q;

int main () {
    cin >> N >> K;

    if (N == K) {
        cout << 0 << endl;
    } else {
        q.push(make_pair(N, 0));
    }
    while (q.empty() == false) {
        pair<int, int> p = q.front();
        q.pop();
        int pos = p.first;
        int time = p.second;

        if (pos + 1 == K) {
            cout << time + 1 << endl;
            break;
        } else {
            if (pos + 1 <= 100000 && visited[pos + 1] == false) {
                q.push(make_pair(pos + 1, time + 1));
                visited[pos + 1] = true;
            }
        }

        if (pos - 1 == K) {
            cout << time + 1 << endl;
            break;
        } else {
            if (0 <= pos - 1 && visited[pos - 1] == false) {
                q.push(make_pair(pos - 1, time + 1));
                visited[pos - 1] = true;
            }
        }

        if (pos * 2 == K) {
            cout << time + 1 << endl;
            break;
        } else {
            if (pos * 2 <= 100000 && visited[pos * 2] == false) {
                q.push(make_pair(pos * 2, time + 1));
                visited[pos * 2] = true;
            }
        }
    }

    return 0;
}