#include <bits/stdc++.h>

using namespace std;

int main(){
    int m = 0; cin >> m;
    //开辟一块空间用来保存每一种类优惠券的状态
    //第一位表示优惠券的数目，第二位表示优惠券的上次被用掉的时刻
    vector<vector<int>> coupons(500005, vector<int>(2, 0));
    set<int> marks;
    for(int i=1;i<=m;i++){
        char sign = ' '; cin >> sign;
        if(sign != '?'){
            int x = 0; cin >> x;
            //记录优惠券的操作
            int opt = sign=='I'?1:-1;
            coupons[x][0] += opt;
            if(coupons[x][0]>1 || coupons[x][0]<0){
                //在marks里面，如果有发现离上一次用掉最早的不确定操作
                //利用该不确定操作来让所有流程变得合理
                if(marks.lower_bound(coupons[x][1]) == marks.end()){
                    cout << i << endl; return 0;
                }
                marks.erase(marks.lower_bound(coupons[x][1]));
                coupons[x][0] = min(max(coupons[x][0], 0), 1);
            }
            //更新该种类优惠券的上一次被用掉的时刻
            coupons[x][1] = i;
        }
        else    marks.insert(i);
    }
    cout << -1 << endl;
    return 0;
}