//#include <bit/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void process(string& s, unordered_map<string, string>& table){
    int start = 0, end = 0;
    int lens = s.size();
    string tmp;
    for(int i=0;i<lens;i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            tmp.push_back(s[i]);
        }
        else{
            if(tmp.empty()) cout << s[i];
            else{
                if(table.find(tmp)!=table.end())    cout << table[tmp] << s[i];
                else    cout << tmp << s[i];
                tmp.clear();
            }
        }
    }
    if(!tmp.empty()){
        if(table.find(tmp)!=table.end())    cout << table[tmp];
        else    cout << tmp;
    }
    cout << endl;
}

int main(){
    unordered_map<string, string> table;
    string str;
    while(getline(cin, str)){
        if(str=="START")  continue;
        else if(str=="END") break;
        else{
            int pos = str.find(' ');
            string first = str.substr(0,pos), second = str.substr(pos+1);
            table[second] = first;
        }
    }
    while(getline(cin, str)){
        if(str=="START")  continue;
        else if(str=="END") break;
        else{
            process(str, table);
        }
    }
    return 0;
}