// Knapsack problem
#include <iostream>
#include <vector>

using namespace std; 
 
// Get maximum value of two numbers
int max(int a, int b) { 

	return (a > b) ?
		a : b; 
}
  
// KnapSack problem
int knapSack(int W, vector<int> weightThing, vector<int> values, int i) {  

	if (i == 0 || W == 0)  
		return 0;  

	if (weightThing[i-1] > W)
		return knapSack(W, weightThing, values, i-1);
	  
	else return max(values[i-1]+knapSack(W-weightThing[i-1], weightThing, values, i-1), knapSack(W, weightThing, values, i-1) );  
}  
  
int main() {

	vector<int> values;			// Value of things
	vector<int> weightThing;	// Weight of indivudual things
	int W = 12; 				// Weight

	
	values.push_back(20);
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);

	weightThing.push_back(300000);
	weightThing.push_back(5);
	weightThing.push_back(6);
	weightThing.push_back(7);

	cout << endl << endl << knapSack(W, weightThing, values, values.size()) << endl;  

	return 0;  
}  