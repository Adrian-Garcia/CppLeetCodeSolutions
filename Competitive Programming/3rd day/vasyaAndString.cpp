#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string word;

	unsigned long long int n; 
	unsigned long long int k;

	unsigned long long int j = 0;
	unsigned long long int count = 0;
	unsigned long long int res = 0;

	cin >> n >> k >> word;

	for (int i=0; i<n; i++) {
		
		if ('a' != word[i])
			count++;

		while (count > k)  {

			if ('a' != word[j++])
				count--;
		}

		res = max(i-j+1, res);
	}

	count = 0;
	j = 0;

	for (int i=0; i<n; i++) {
		
		if ('b' != word[i])
			count++;
		
		while (count > k) {

			if ('b' != word[j++])
				count--;
		}

		res = max(i-j+1, res);
	}

	cout << res << endl;

	return 0;
}