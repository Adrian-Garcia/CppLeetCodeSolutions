#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define f(x) (x)*(x+1)/2

int formula (int k) {
	return (k*(k+1))/2;
}

int main() {
	
	long long int n;
	
	int i=1;
	int j=1;

	bool flag;
	
	cin >> n;

	flag=false;

	for(i=1; formula(i)+formula(j)<=n && !flag; i++) {
		
		for(j=i; formula(i)+formula(j)<=n && !flag; j++) 
			if(formula(i)+formula(j) == n) 
				flag=true;

		j=1;
	}

	if(flag)
		cout << "YES" << endl;

	else 
		cout << "NO" << endl;

	return 0;
}