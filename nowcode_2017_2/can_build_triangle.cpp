#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool isValidTriangle(int a, int b, int c){
	if(a+b>c)	return true;
	else	return false;
}

int getResult(vector<int>& nums, int n){
	int count = 0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(isValidTriangle(nums[i],nums[j],nums[k]))	++count;
			}
		}
	}
	return count;
}

int main(){
	int n=0;
	while (cin >>n){
		vector<int> nums(n,0);
		for(int i=0;i<n;i++)	cin >> nums[i];
		if(n<3){
			cout << 0 << endl;
			continue;
		}
		sort(nums.begin(),nums.end());
		int x = getResult(nums,n);
		cout << x << endl;
	}
	return 0;
}