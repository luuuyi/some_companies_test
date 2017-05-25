//#include <bit/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string process(string& s, unordered_map<string, string>& table){
    int start = 0, end = 0;
    int lens = s.size();
    bool is_word = true, is_split = false;
    for(int i=0;i<lens;i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            if(is_word){
                is_split = false;
            }
            else{
                start = i;
                is_word = !is_word;
            }
        }
        else{
            if(is_split){
                is_word = false;
                cout << s[i];
            }
            else{
                if(table.find(s.substr(start, i - start))!=table.end()) cout << table[s.substr(start, i - start)];
                else    cout << s.substr(start, i - start);
                is_split = !is_split;
            }
        }
    }
    cout << endl;
}

int main(){
    bool is_first = true;
    unordered_map<string, string> table;
    string str;
    while(getline(cin, str)){
        if(str=='START'&&is_first)  continue;
        else if(str=='END') break;
        else{
            int pos = str.find(' ');
            string first = str.substr(0,pos), second = str.substr(pos);
            table[second] = first;
        }
    }
    string unsolved;
    while(getline(cin, str)){
        if(str=='START'&&is_first)  continue;
        else if(str=='END') break;
        else{
            unsolved = str;
        }
    }
    process(unsolved, table);
    return 0;
}