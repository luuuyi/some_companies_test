#include <bits/stdc++.h>

using namespace std;

int main(){
    int l = 0, r = 0;
    cin >> l >> r;
    vector<int> res(9, 0);
    //所有约数，保留约数的最高位
    for(int i=0;i<9;i++){
        int divisor = i+1;
        //
        int left = l + (l%divisor==0?0:divisor-(l%divisor));
        int right = r - (r%divisor==0?0:r%divisor);
        if(r >= l)  res[i] = (r - l)/divisor + 1;
        else res[i] = 0;
        cout << res[i] << endl;
    }
    return 0;
}