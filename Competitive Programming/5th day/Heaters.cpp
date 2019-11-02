// #include <bits/stdc++.h>
	// memset(v,0,sizeof(v));
#include <iostream>

using namespace std;

int main() {

	int n;
	int r;
	int k;

	int v[100000];

	cin >> n >> r;

	for(int i=1; i<=n; i++){

		cin >> k;

		if(k == 1)
			for(int j = max(1, i - r + 1); j<=min(i + r - 1, n); j++) 
				v[j] = max(v[j], i);
	}

	int i = 1;
	int res = 0;
	bool flag = false;

	while(i <= n && !flag){

		if(!v[i])
			flag = true;

		res++;
		i = v[i] + r;
	}

	(flag) ?
		cout << -1 << endl:
		cout << res << endl;

	return 0;
}
