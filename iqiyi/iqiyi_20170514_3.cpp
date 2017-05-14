#include <iostream>
#include <vector>

using namespace std;

long long findMax(vector<int>& nums) {
	long long ret = 0;
	while (nums.size() >= 1) {
		long long tmp = 0;
		int idx = 0;
		for (int k = 0; k < nums.size(); k++)
		{
			long long result = nums[k] * (k - 1 < 0 ? 1 : nums[k - 1])*(k + 1 >= nums.size() ? 1 : nums[k + 1]);
			if (result > tmp) {
				tmp = result;
				idx = k;
			}
			else if (result == tmp&&nums[k] < nums[idx]) {
				tmp = result;
				idx = k;
			}
		}
		ret += tmp;
		nums.erase(nums.begin() + idx);
	}
	return ret;
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