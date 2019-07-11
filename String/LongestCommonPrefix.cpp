/*
14. Longest Common Prefix

	Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".

	Example 1:
		Input: ["flower","flow","flight"]
		Output: "fl"
	
	Example 2:
		Input: ["dog","racecar","car"]
		Output: ""
		Explanation: There is no common prefix among the input strings.
	
	Note:
		All given inputs are in lowercase letters a-z.
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

string ToStr(char c) {
   return string(1, c);
}

string longestCommonPrefix(vector<string>& strs) {

	string lcp, auxiliar;
	char aux;
	int min = INT_MAX;
	bool flag = true;

	// Find smallest integer
	for (int i=0; i<strs.size(); i++) {

		auxiliar = strs[i];

		if (min > auxiliar.length())
			min = auxiliar.length();
	}

	// Look in letters
	for (int i=0; i<min && flag; i++) {
				
		// Look in strings
		for (int j=0; j<strs.size() && flag; j++) {			
			
			auxiliar = strs[j];
			
			if (j=0)
				auxiliar[i] = aux;
			
			cout << auxiliar[i] << " " << aux;

			if (aux != auxiliar[i]) {
				flag = false;
				break;
			}
		}
		
		lcp.insert(i, ToStr(aux));	
	}	
	
	return lcp;
}

int main() {

	cout << "flower, flow, flight" << endl;

	std::vector<string> strs;

	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");

	string s = longestCommonPrefix(strs);

	cout << s << endl;

	return 0;
}
