#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getResult(vector<int>& nums, int k) {
	int tmp = nums[nums.size() - 1];
	while (tmp) {
		int total = 0;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] / tmp >= 1) {
				total += nums[i] / tmp;
				if (total >= k)	return tmp;
			}
			else	break;
		}
		--tmp;
	}
	return 0;
}

int main() {
	int k = 0;
	cin >> k;
	vector<int> nums;
	int x = 0;
	while (cin >> x) {
		nums.push_back(x);
	}
	sort(nums.begin(), nums.end());
	cout << getResult(nums, k) << endl;
	return 0;
}