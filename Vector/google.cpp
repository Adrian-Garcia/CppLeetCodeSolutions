#include <iostream>
//#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> N, int K)  {

    if (N.size() == 0)
        return N;

    vector<int> A = N;
    vector<int> B = N;

    for (int i=0; i<N.size()-K; i++)
        A.erase(A.begin());

    for (int i=0; i<N.size()-K; i++)
        B.pop_back();

    for (int i=0; i<A.size(); i++) {
        
        if (A[i] > B[i]) {
            return A;
        }

        if (A[i] < B[i]) {
            return B;
        }
    }

    return A;
}

int main() {

  vector<int> N;

  N.push_back(10);
  N.push_back(4);
  N.push_back(3);
  N.push_back(2);
  N.push_back(5);

  vector<int> res = solution(N, 4);

  for (int i=0; i<res.size(); i++)
    cout << res[i] << " ";
}