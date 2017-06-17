#include <bits/stdc++.h>

using namespace std;

//主要注意一下因为数据范围较大，需要使用long long型变量
long long calcNum(vector<long long>& grass, int n, long long a){
    long long niuniu = a;
    for(int i=0;i<n;i++){
        if(niuniu == grass[i])  niuniu *= 2;
    }
    return niuniu;
}

//逻辑题目，按题意去编程即可
int main(){
    int n = 0; 
    long long a = 0;
    cin >> n >> a;
    vector<long long> grass(n, 0);
    for(int i=0;i<n;i++)    cin >> grass[i];
    cout << calcNum(grass, n, a) << endl;
    return 0;
}