#include <bits/stdc++.h>

using namespace std;

int calcNum(string &s){
    int pos = 0, lens = s.size();
    int ret = 0;
    //过滤掉前缀为 ? 的字符串
    while(pos < lens && s[pos] == '?')  ++pos;
    for(int i=pos+1;i<lens;i++){
        if(s[i] == '?'){
            s[i] = (s[i-1] == 'A'?'B':'A');
        }
        else{
            if(s[i] == s[i-1])  ++ret;
        }
    }
    return ret;
}

//丑陋的数字，字符串开头的一系列 ? 字符是可以抵消的，后面的 ? 字符可以按贪心算法来做
int main(){
    string s;
    cin >> s;
    cout << calcNum(s) << endl;
    return 0;
}