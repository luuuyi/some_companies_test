#include <bits/stdc++.h>

using namespace std;

set<int> table({11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 ,73, 79, 83, 89, 97});

bool isStrange(int n){
	if(n<10)	return false;
	vector<int> nums;
	int tmp = n;
	while(tmp){
		nums.push_back(tmp%10);
		tmp /= 10;
	}
	int lens = nums.size();
	for(int i=0;i<lens;i++){
		for(int j=0;j<lens;j++){
			if(i!=j){
				if(table.find(nums[i]*10+nums[j])!=table.end())	return true;
			}
		}
	}
	return false;
}

int getResult(int a, int b){
	int ret = 0;
	for(int i=a;i<=b;i++){
		if(isStrange(i))	++ret;
	}
	return ret;
}

int main(){
	int a = 0, b = 0;
	cin >> a >> b;
	cout << getResult(a, b) << endl;
	return 0;
}