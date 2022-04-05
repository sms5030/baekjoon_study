#include <iostream>
#include <vector>

using namespace std;

vector<long long int> A;
long long int N, B, C;
int main() {
  cin >> N;
  long long int temp = 0;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    A.push_back(temp);
  }
  cin >> B >> C;

  long long int result = 0;
  for (int i = 0; i < N; i++) {
    int a = A[i];
    result++;
    a -= B;
    if (a > 0) {
      result += (a / C);
      if (a % C > 0) {
        result++;
      } 
    }
  }

  cout << result << endl;
}