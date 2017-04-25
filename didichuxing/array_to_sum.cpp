#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

long long getResult(vector<int>& nums, int sum){
	int n = nums.size();
	vector<vector<long long>> dp(n+1,vector<long long>(sum+1,0));
	for(int i=0;i<=n;i++)	dp[i][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(nums[i-1]<=j)	dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
			else	dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}

int main(){
	int n = 0, sum = 0;
	cin >> n >> sum;
	vector<int> nums(n);
	for(int i=0;i<n;i++)	cin >> nums[i];
	long long ret = getResult(nums,sum);
	cout << ret << endl;
	return 0;
}