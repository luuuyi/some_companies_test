#include <iostream>
#include <vector>

using namespace std;

//区间dp solver
long long findMax(vector<int>& nums) {
	int lens = nums.size();
	if(lens==0)	return 0;
	nums.insert(nums.begin(),1); nums.insert(nums.end(),1);
	vector<vector<long long>> dp(lens+2,vector<long long>(lens+2,0));
	for(int k=1;k<=lens;k++){
		for(int i=1;i<=lens-k+1;i++){               //attention
			int j = i+k-1;
			for(int x=i;x<=j;x++){
				dp[i][j] = max(dp[i][j], dp[i][x-1] + nums[x]*nums[i-1]*nums[j+1] + dp[x+1][j]);
			}
		}
	}
	return dp[1][lens];
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	cout << findMax(nums) << endl;
	return 0;
}