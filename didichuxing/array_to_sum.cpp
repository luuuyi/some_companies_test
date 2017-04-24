#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void myPermutation(vector<int>& nums,int cur, int lens,int& res, int sum){
	if(sum==0||cur>=lens){
		if(sum==0)	res++;
		return;
	}
	for(int i=cur;i<lens;i++){
		if(sum-nums[i]>=0){
			myPermutation(nums,i+1,lens,res,sum-nums[i]);
		}
		else	break;
	}
}

int getResult(vector<int>& nums, int sum){
	sort(nums.begin(),nums.end());
	int lens = nums.size();
	int res = 0;
	myPermutation(nums,0,lens,res,sum);
	return res;
}

int main(){
	int n = 0, sum = 0;
	cin >> n >> sum;
	vector<int> nums(n);
	for(int i=0;i<n;i++)	cin >> nums[i];
	int ret = getResult(nums,sum);
	cout << ret << endl;
	return 0;
}