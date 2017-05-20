#include <bits/stdc++.h>

using namespace std;

long long getResult(vector<int>& nums, int n){
	long long ret = 0;
	sort(nums.begin(), nums.end());
	for(int i=1;i<=n/3;i++){
		ret += nums[n-i*2];
	}
	return ret;
}

int main(){
	int n = 0;
	cin >> n;
	vector<int> nums(3*n, 0);
	for(int i=0;i<3*n;i++)	cin >> nums[i];
	cout << getResult(nums, 3*n) << endl;
	return 0;
}