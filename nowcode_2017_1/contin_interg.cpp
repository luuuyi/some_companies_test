#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    while(cin>>n){
        vector<int> nums(n,0);
        map<int,int> mp;
        bool flag = false;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            if(++mp[nums[i]]>=2)    flag = true;
        }
        if(flag){
            cout << "mistake" << endl;
            continue;
        }
        sort(nums.begin(),nums.end());
        if(nums[n-1] - nums[0] + 1==n){
            if(nums[0]==1)  cout << to_string(nums[n-1]+1) << endl;
            else    cout << to_string(nums[0]-1) << " " << to_string(nums[n-1]+1) << endl;
        }
        else if(nums[n-1] - nums[0] + 1==n+1){
            for(int i=0;i<n;i++){
                if(nums[i]!=nums[0]+i){
                  cout << to_string(nums[0]+i) << endl;
                  break;
                }
            }
        }
        else    cout << "mistake" << endl;
    }
    return 0;
}