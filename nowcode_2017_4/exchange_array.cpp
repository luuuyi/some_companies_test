#include <bits/stdc++.h>

using namespace std;

int calcNum(vector<int>& nums, int n){
    set<vector<int>> table;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(nums[i], nums[j]);
            table.insert(nums);
            swap(nums[i], nums[j]);
        }
    }
    return table.size();
}

//逻辑题目，按题意去编程即可
int main(){
    int n = 0; 
    cin >> n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)    cin >> nums[i];
    cout << calcNum(nums, n) << endl;
    return 0;
}