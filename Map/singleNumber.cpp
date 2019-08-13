#include <iostream>
#include <vector>
#include <map>

using namespace std;

void search(int key, map<int, int>& search) {

	map<int, int>::iterator it = search.find(key)

	if (it != search.end())
		(it*).second++;
	else
		search.insert(pair<int, int> thisPair(key, 1));
}

void once(map<int, int>& search) {
	
	for (it=search.begin(); it!=search.end(); it++)
		if (it->second == 1)
			return it->second;
}

int singleNumber(vector<int>& nums) {

	map<int, int> search;

	for (int i=0; i<nums.size(); i++)
		search(nums[i], search);

	return once(search);

}

int main() {

	return 0;
}