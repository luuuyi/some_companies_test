#include <bits/stdc++.h>

using namespace std;

int calcNum(vector<int>& height, int n){
    //排序原本的身高序列，然后用一个deque来维护
    sort(height.begin(), height.end());
    deque<int> children;
    int max_val = 0;
    //每一次头尾交替安放小朋友，这样能保证永远使得身高差最高只是原来排序序列n和n+2的差值，不会更多
    for(int i=0;i<n;i++){
        if(i == 0)  children.push_back(height[i]);
        else{
            if(i&0x01){
                int tmp = children.back();
                children.push_back(height[i]);
                max_val = max(max_val, children.back()-tmp);
            }
            else{
                int tmp = children.front();
                children.push_front(height[i]);
                max_val = max(max_val, children.front()-tmp);
            }
        }
    }
    //因为是围成一个圆圈的，最后还要计算头尾的差值
    max_val = max(max_val, abs(children.front()-children.back()));
    return max_val;
}

//求围成一个圆圈的小朋友相互之间的身高差，要使得最大身高差最小
int main(){
    int n = 0;
    cin >> n;
    vector<int> height(n, 0);
    for(int i=0;i<n;i++)    cin >> height[i];
    cout << calcNum(height, n) << endl;
    return 0;
}