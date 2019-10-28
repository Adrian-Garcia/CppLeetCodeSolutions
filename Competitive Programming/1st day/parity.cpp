/*
	C - Parity 

	You are given an integer n (n≥0) represented with k digits in base (radix) b. So,

	n=a1⋅bk−1+a2⋅bk−2+…ak−1⋅b+ak.
	For example, if b=17,k=3 and a=[11,15,7] then n=11⋅172+15⋅17+7=3179+255+7=3441.

	Determine whether n is even or odd.

	Input
		The first line contains two integers b and k (2≤b≤100, 1≤k≤105) — the base of the number and the number of digits.

		The second line contains k integers a1,a2,…,ak (0≤ai<b) — the digits of n.

		The representation of n contains no unnecessary leading zero. That is, a1 can be equal to 0 only if k=1.

	Output
		Print "even" if n is even, otherwise print "odd".

		You can print each letter in any case (upper or lower).
*/ 

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

long long int fastPow(long long int b, long long int n) {

	for (int i=0; i<n; i++)
		b*=b;

	return b;
}


int main() {

	long long int b;
	long long int k;
	
	long long int currVal;
	long long int result = 0;

	unsigned long long int val;

	string resInString;

	cin >> b;
	cin >> k;

	for (int i=0; i<k; i++) {
		
		cin >> currVal;

		val = currVal * (fastPow(b, k-i-1));
		cout << val << " ";

		if (val % 2 == 0)
			result ++;
	}

	cout << endl;

	if (result % 2)
		cout << "even" << endl;
	else
		cout << "odd" << endl;

	return 0;
}