//#include <bit/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int count = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int tmp = i + 2*j + 5*(n-i-j);
            if(tmp == m)    ++count;
        }
    }
    cout << count << endl;
    return 0;
}