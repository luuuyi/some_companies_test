#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//特别难的一个题
//题解：https://www.nowcoder.com/discuss/28544?type=0&order=0&pos=5&page=2
int main(){
    int n = 0;
    cin >> n;
    vector<vector<vector<double>>> dp(2, vector<vector<double>>(n+5, vector<double>(n+5, 0)));
    //首先初始化初始值
    dp[0][1][0] = 1.0;
    for(int i=1;i<=n;i++){
        int cur = (i&0x01), old = 1 - cur;
        //由于压缩了空间，只用了0和1来表达两个状态，所以需要每一次更新cur状态的值为0
        for(int j=1;j<=i+1;j++){
            for(int k=0;k<j;k++)    dp[cur][j][k] = 0;
        }
        //通过old状态来计算cur状态
        for(int j=1;j<=i;j++){
            for(int k=0;k<j;k++){
                //只判断old状态有值的情况
                if(dp[old][j][k] > 0){
                    //0.5的概率向右，考虑边界情况
                    int tmp_j = j, tmp_k = k+1;
                    if(tmp_k == tmp_j)  tmp_j++;
                    dp[cur][tmp_j][tmp_k] += 0.5*dp[old][j][k];
                    //0.5的概率向左，同样需要考虑边界情况
                    tmp_j = j; tmp_k = k-1;
                    if(tmp_k == -1){  tmp_j++; tmp_k = 0;}
                    dp[cur][tmp_j][tmp_k] += 0.5*dp[old][j][k];
                }
            }
        }
    }
    //计算期望，根据红色方格的数量作为权值来计算
    double ret = 0;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<i;j++){
            ret += i*dp[n&0x01][i][j];
        }
    }
    cout << fixed << setprecision(1) << ret << endl;
    return 0;
}