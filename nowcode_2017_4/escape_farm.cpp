#include <bits/stdc++.h>

using namespace std;

//特别难的一个题
//题解：https://www.nowcoder.com/discuss/28544?type=0&order=0&pos=5&page=2
int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    vector<vector<int>> dp(k+1, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=k;j>=1;j--){
            for(int x=0;x<n;x++){
                dp[j][x] = (dp[j][x] + dp[j-1][x-i<0?x-i+n:x-i])%1000000007;
            }
        }
    }
    cout << dp[k][0] << endl;
    return 0;
}