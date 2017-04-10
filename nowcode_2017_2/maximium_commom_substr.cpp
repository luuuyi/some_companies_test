#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int getMaxiCommonSubstrSize(string& s1, string& s2){
	int lens_1 = s1.size(), lens_2 = s2.size();
	int max_res = 0;
	vector<vector<int>> dp(lens_1+1,vector<int>(lens_2+1,0));
	for(int i=1;i<=lens_1;i++){
		for(int j=1;j<=lens_2;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j] > max_res)	max_res = dp[i][j];
			}
			else	dp[i][j] = 0;
		}
	}
	return max_res;
}

int main(){
	string str1, str2;
	while (getline(cin,str1)){
		getline(cin,str2);
		if(str1.size()==0||str2.size()==0){
			cout << 0 << endl;
			continue;
		}
		int n = getMaxiCommonSubstrSize(str1,str2);
		cout << n << endl;
	}
	return 0;
}