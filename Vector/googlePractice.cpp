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
        A.erase(A.being() + 0);

    for (int i=0; i<N.size()-K; i++)
        A.pop_back();

    for (int i=0; i<A.size(); i++) {
        
        if (A[i] > B[i]) {
            return A;
        }

        if (A[i] < B[i]) {
            return B;
        }
    }

    return A[i];
}

vector<int> toIntVector(string str) {
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

string fromIntVector(vector<int> arr)
{
  string out = "";
  for (int i=0; i<arr.size(); i++) {
    out += to_string(arr[i]);
    if (i != arr.size() - 1) {
      out += ",";
    }
  }
  return out;
}

int main() {



}
