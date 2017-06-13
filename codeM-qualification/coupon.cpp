#include <bits/stdc++.h>

using namespace std;

int main(){
    int m = 0;
    while(cin >> m){
        if(m == 0){
            cout << -1 << endl;
            continue;
        }
        map<int, vector<int>> status;
        set<int> unknown;
        int ret = -1; bool is_continue = true;
        for(int i=0;i<m;i++){
            if(is_continue){
                char action; cin >> action;
                if(action == '?')   set.insert(i);
                else if(action == 'I'){
                    int num = 0; cin >> num;
                    if(status.find(num) == status.end())    status[num] = vector<int>({1, i});
                    else{
                        if(status[num][0]+1 > 1){
                            for(auto k=unknown.begin(); k!=unknown.end(); k++){
                                if(*k > status[num][1]){
                                    unknown.erase(k); status[num][1] = i;
                                    break; 
                                }
                            }
                            if(status[num][1] == i) continue;
                            else{
                                is_continue = false; ret = i+1;
                            }
                        }
                    }
                }
                else if(action == 'O'){
                    int num = 0; cin >> num;
                    if(status.find(num) == status.end() && unknown.empty()){    is_continue = false; ret = i+1;}
                    else if(status.find(num) == status.end() && !unknown.empty()){
                        for(auto k=unknown.begin(); k!=unknown.end(); k++){
                            if(*k < i){
                                status[num] = vector<int>({0, i}); unknown.erase(k);
                                break;
                            }
                        }
                    }
                }
            }
            else{
                string tmp; cin >> tmp;
            }
        }
        cout << ret << endl;
    }
    return 0;
}