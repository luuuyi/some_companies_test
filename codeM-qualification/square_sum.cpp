#include <bits/stdc++.h>

using namespace std;

//没仔细继续考虑，先把所以题刷掉再说
long long getResult(vector<int>& a, int n, vector<int>& b, int m){
    long long min_val = 0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<=m-n;i++){
        long long tmp = 0;
        for(int j=0;j<n;j++){
            tmp += pow(a[j] - b[i+j], 2);
        }
        min_val = min(min_val, tmp);
    }
    return min_val;
}

//开胃菜，滑动窗口解题，根据给定的数据范围，时间复杂度为O(n*n)还是能接受的
int main(){
    int n = 0, m = 0;
    cin >> n;
    vector<int> a(n, 0);
    for(int i=0;i<n;i++)    cin >> a[i];
    cin >> m;
    vector<int> b(m, 0);
    for(int i=0;i<m;i++)    cin >> b[i];
    cout << getResult(a, n, b, m) << endl;
    return 0;
}