#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Edge {
  int v;
  int u;
  long long int weight;
} EDGE;

bool compareFunc(EDGE a, EDGE b);

int V, E;
vector<EDGE> v;
vector<int> root;
vector<EDGE> success;

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    EDGE e;
    cin >> e.v >> e.u >> e.weight;
    v.push_back(e);
  }
  for (int i = 0; i < V; i++) {
    root.push_back(-1);
  }

  sort(v.begin(), v.end(), compareFunc);

  for (int i = 0; i < E; i++) {
    int vv = v[i].v - 1;
    int vu = v[i].u - 1;
    if (root[vv] == -1 && root[vu] == -1) {
      int min = vv > vu ? vu : vv;
      root[vv] = min;
      root[vu] = min;
      success.push_back(v[i]);
    } else if (root[vv] != root[vu]) {
      int min = 100000;
      int originalRoot = 0;
      bool isChangedRoot = false;
      if (root[vv] == -1) {
        min = vv > root[vu] ? root[vu] : vv;
        isChangedRoot = vv < root[vu];
        originalRoot = root[vu];
      } else if (root[vu] == -1) {
        min = vu > root[vv] ?  root[vv] : vu ;
        isChangedRoot = vu < root[vv];
        originalRoot = root[vv];
      } else {
        int min1 = vv > vu ? vu : vv;
        int min2 = root[vv] > root[vu] ? root[vu] : root[vv];
        min = min1 > min2 ? min2 : min1;
        isChangedRoot = min1 < min2;
        originalRoot = root[vv] > root[vu] ? root[vu] : root[vv];
      }
      root[vv] = min;
      root[vu] = min;

      if (isChangedRoot) {
        for (int j = 0; j < V; j++) {
          if (root[j] == originalRoot) {
            root[j] = min;
          }
        }
      }
      success.push_back(v[i]);
    }
  }

  long long int weight = 0;
  int successCount = success.size();
  for (int i = 0; i < successCount; i++) {
    weight += success[i].weight;
  }

  cout << weight << endl;

  return 0;
}

bool compareFunc(EDGE a, EDGE b) {
  return a.weight < b.weight;
}
