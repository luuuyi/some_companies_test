#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int calcuCost(string& s, int type){
	int nums_of_zero = 0, nums_of_one = 0;
	for (int i = 0; i<s.size(); i++){
		if (s[i] == '0')	nums_of_zero++;
		else	nums_of_one++;
	}
	if (type)	return nums_of_one;
	else	return nums_of_zero;
}

int main(){
	int x = 0, n = 0, m = 0;
	while (cin >> x >> n >> m){
		vector<string> goods(x);
		for (int i = 0; i<x; i++)	cin >> goods[i];
		vector<vector<int>> dp(x + 1);
		dp[0].assign({ n, m, 0 });
		int max_res = 0;
		for (int i = 1; i <= x; i++){
			int max = 0;
			for (int j = i - 1; j >= 0; j--){
				int classes = dp[j].size() / 3;
				for (int k = 0; k<classes; k++){
					if (dp[j][k * 3] >= calcuCost(goods[i - 1], 0) && dp[j][k * 3 + 1] >= calcuCost(goods[i - 1], 1)){
						if (dp[j][k * 3 + 2] + 1>max){
							max = dp[j][k * 3 + 2] + 1;
							dp[i].clear();
							dp[i].push_back(dp[j][k * 3] - calcuCost(goods[i - 1], 0));
							dp[i].push_back(dp[j][k * 3 + 1] - calcuCost(goods[i - 1], 1));
							dp[i].push_back(dp[j][k * 3 + 2] + 1);
						}
						else if (dp[j][k * 3 + 2] + 1 == max){
							dp[i].push_back(dp[j][k * 3] - calcuCost(goods[i - 1], 0));
							dp[i].push_back(dp[j][k * 3 + 1] - calcuCost(goods[i - 1], 1));
							dp[i].push_back(dp[j][k * 3 + 2] + 1);
						}
					}
				}
			}
			if (max>max_res)	max_res = max;
		}
		cout << max_res << endl;
	}
	return 0;
}