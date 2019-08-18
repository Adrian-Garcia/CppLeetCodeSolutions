#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> A) {
	
	if (A.size() < 2)
    	return A.size();
  
	int max = A[0];
	int rows = 1;
	  
	for (int i=1; i<A.size(); i++) {
	    
		if (A[i] > max) {
	      
	    	rows++;
	    	max = A[i];
	    }
	}
  
	return rows;
}


int main() {

	vector<int> A;

	A.push_back(5);
	A.push_back(4);
	A.push_back(3);
	A.push_back(6);
	A.push_back(1);

	cout << solution(A) << endl;

	return 0;
}