#include <bits/stdc++.h>

//bad solution
using namespace std;

/*int getResult(vector<int>& nums, int n){
	if(n <= 2)	return 1;
	int ret = 1;
	bool is_asc = false, is_des = false;
	for(int i=0;i<n-1;i++){
		if(nums[i+1] == nums[i])	continue;
		else if(nums[i+1] > nums[i]){
			is_asc = true;
			if(is_des){
				ret++; is_des = false;
			}
		}
		else{
			is_des = true;
			if(is_asc){
				ret++; is_asc = false;
			}
		}
	}
	return ret;
}

int main() {
	int n=0;
	cin >> n;
	vector<int> nums(n,0);
	for(int i=0;i<n;i++){
		cin >> nums[i];
	}
	cout << getResult(nums, n) << endl;
	return 0;
}*/

int main() {
	int n=0;
	cin >> n;
	vector<int> nums;
	int x = 0, ret = 1;
	for(int i=0;i<n;i++){
		cin >> x;
		if(nums.size()<=1)	nums.push_back(x);
		else{
			if(nums[0] <= nums.back() && nums.back() <= x)	nums.push_back(x);
			else if(nums[0] >= nums.back() && nums.back() >= x)	nums.push_back(x);
			else{
				ret++; nums.clear();
				nums.push_back(x);
			}
		}
	}
	cout << ret << endl;
	return 0;
}