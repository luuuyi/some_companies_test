#include <bits/stdc++.h>

using namespace std;

int calcNum(string &s){
    int lens = s.size();
    int ret = 0;
    for(int i=0;i<lens;i++){
        if(i&0x01){
            ret += (s[i]=='B'?0:1);
        }
        else{
            ret += (s[i]=='W'?0:1);
        }
    }
    //最后再判断下谁比较小
    return ret<lens-ret?ret:lens-ret;
}

//比较简单的一个题
//统计一种交错排列的改变数，另一种交错排列的改变数即为 总数-上一次的改变数
int main(){
    string s;
    cin >> s;
    cout << calcNum(s) << endl;
    return 0;
}