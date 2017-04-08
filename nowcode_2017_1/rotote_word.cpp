#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void registeWord(map<string,int>& mp, string& s){
    int lens = s.size();
    mp[s] = 1;
    for(int i=1;i<=lens-1;i++){
        mp[s.substr(i)+s.substr(0,i)] = 1;
    }
    return;
}

int main(){
    int n;
    while(cin>>n){
        map<string,int> mp;
        int count = 0;
        for(int i=0;i<n;i++){
            string tmp; cin >> tmp;
            if(mp.find(tmp)==mp.end()){
                ++count;
                registeWord(mp,tmp);
            }
        }
        cout << count << endl;
    }
    return 0;
}