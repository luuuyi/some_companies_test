#include <bits/stdc++.h>

using namespace std;

// 用一个set来维护，因为去掉某一位字符以后有可能会遇到重复的值
// 最后统计set里面的元素个数即可
int calcNum(string s){
    set<string> table;
    int lens = s.size();
    for(int i=0;i<lens;i++){
        table.insert(s.substr(0, i)+s.substr(i+1));
    }
    return table.size();
}

int main(){
    string s;
    cin >> s;
    cout << calcNum(s) << endl;
    return 0;
}