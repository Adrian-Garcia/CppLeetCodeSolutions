#include <iostream>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int> nums) {
    
    int res=nums[0];
    
    for(int i=1;i<nums.size();i++){
        
		cout << res << " ";
        res^=nums[i];
        cout << res << endl;
    } cout << endl;
    
    return res;
}

int main() {
	
	vector<int> nums;

	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);

	cout << singleNumber(nums);

	return 0;
}
