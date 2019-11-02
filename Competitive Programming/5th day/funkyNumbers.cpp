#include<iostream>

// using namespace std;

int formula (unsigned long long int k) {
	return (k*(k+1))/2;
}

int main() {
	
	unsigned long long int n;
	
	unsigned long long int i=1;
	unsigned long long int j=1;

	bool flag = false;
	
	std::cin >> n;

	for(i=1; formula(i)+formula(j)<=n && !flag; i++) {
		
		// cout << formula(i+1) << " " << formula(j) << "\t\t";
		// cout << formula(i+1)+formula(j) << "\t\t";

		for(j=i; formula(i)+formula(j)<=n && !flag; j++) {

			// cout << formula(i+1) << " " << formula(j) << " ";
			// cout << formula(i+1)+formula(j) << " ";

			if(formula(i)+formula(j) == n) 
				flag=true;
		}

		j=1;
	}

	(flag) ?
		std::cout << "YES" << std::endl:
		std::cout << "NO" << std::endl;

	return 0;
}