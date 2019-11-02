#include<iostream>

int main(){
	
	int n; 
	int a; 
	int b; 
	bool res;

	std::cin>>n;
	
	a = 1;
	b = 1;

	res = false;
	
	for(int i=2; a<n; a+=i, b=1, i++)
		for(int j=2; b<=n-a; b+=j, j++)
			if (a+b==n)
				res = true;

	(res) ?
		std::cout << "YES" << std::endl:
		std::cout << "NO" << std::endl;
}