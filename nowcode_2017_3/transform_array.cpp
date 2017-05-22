//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums, int n){
	for(int i=0;i<n;i++)	cout << nums[i] << endl;
}

void getResult(vector<int>& nums, int n){
	if(n <= 1){
		cout << "YES" << endl;
	}
	for(int i=0;i<n;i++){
		while(nums[i]!=0 && (nums[i]&0x01)==0){
			nums[i] = nums[i] >> 1;
		}
	}
	int res = nums[0];
	bool index = true;
	for(int i=1;i<n;i++){
		if(res != nums[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
	int n = 0;
	cin >> n;
	vector<int> nums(n,0);
	for(int i=0;i<n;i++)	cin >> nums[i];
	getResult(nums, n);
	return 0;
}