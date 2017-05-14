#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

long long findResult(vector<long long>& vecs_p, vector<long long>& vecs_v, int B) {
	int lens = vecs_p.size();
	if (lens == 0)	return 0;
	vector<vector<long long>> dp(lens + 1, vector<long long>(B + 1, 0));
	//if (cur >= lens)	return 0;
	//if(B>= vecs_p[cur])	return max(vecs_v[cur]+ findResult(vecs_p, vecs_v, cur+1,lens, B- vecs_p[cur]), findResult(vecs_p, vecs_v, cur + 1, lens,B));
	//else	return findResult(vecs_p, vecs_v, cur + 1, lens, B);
	for (int i = 1; i <= lens; i++) {
		for (int j = 1; j <= B; j++) {
			if (vecs_p[i - 1] > j)	dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vecs_p[i - 1]] + vecs_v[i - 1]);
			}
		}
	}
	return dp[lens][B];
}

int main() {
	int B = 0;
	cin >> B;
	int p = 0, v = 0;
	vector<long long> vecs_p, vecs_v;
	int k = 4;
	while (cin >> p >> v) {
		vecs_p.push_back(p);
		vecs_v.push_back(v);
		if (k-- == 1)	break;
	}
	int lens = vecs_p.size();
	cout << findResult(vecs_p, vecs_v, B) << endl;
	return 0;
}