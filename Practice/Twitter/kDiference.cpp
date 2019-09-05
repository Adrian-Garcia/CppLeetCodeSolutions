#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> a, int val) {

    int low = 0;
    int big = a.size()-1;
    int mid = (big+low)/2;

    while (low <= big) {

        mid = (big+low)/2;

        if (a[mid] == val)
            return true;

        else if (a[mid] < val)
            low = mid+1;

        else
            big = mid-1;
    }

    return false;
}

int kDifference(vector<int> a, int k) {

    sort(a.begin(), a.end());

    int res = 0;

    for (int i=0; i<a.size(); i++)
        if (binarySearch(a, a[i]-k))
            res++;

    return res;    
}

int main() {

	vector<int> a;

	a.push_back(1);
	a.push_back(5);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);

	cout << kDifference(a, 2) << endl;

	return 0;
}