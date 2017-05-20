#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 0;
	const int INF = 0x3f3f3f3f;
	cin >> n;
	vector<int> nums(n+2, 0);
	vector<int> pre = nums, post = nums;
	nums[0] = nums[n+1] = INF;
	for(int i=1;i<=n;i++)	cin >> nums[i];
	for(int i=1;i<=n;i++)	pre[i] = nums[i-1] < nums[i]?pre[i-1] + 1:1;
	for(int i=n;i>=1;i--)	post[i] = nums[i] < nums[i+1]?post[i+1] + 1:1;
	int ret = 0;
	for(int i=1;i<=n;i++){
		ret = max(ret, pre[i-1]+1);
		ret = max(ret, post[i+1]+1);
		if(nums[i+1] - nums[i-1] >= 2)	ret = max(ret, pre[i-1]+post[i+1]+1);
	}
	cout << ret << endl;
	return 0;
}