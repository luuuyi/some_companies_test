#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
	int min_size = 0, max_size = 0;
	while (cin >> min_size >> max_size){
		int nums = 0; cin >> nums;
		vector<int> fishes(nums, 0);
		map<int, int> mp;
		//int max_size_fish =0x80000000, min_size_fish = 0x7fffffff;
		for (int i = 0; i<nums; i++){
			cin >> fishes[i];
			for (int start = ceil((double)fishes[i] / 10); start <= fishes[i] / 2; start++){
				if (start >= min_size&&start <= max_size)    ++mp[start];
			}
			for (int start = fishes[i] * 2; start <= fishes[i] * 10; start++){
				if (start >= min_size&&start <= max_size)    ++mp[start];
			}
		}
		int res = max_size - min_size + 1 - mp.size();
		cout << res << endl;
	}
	return 0;
}