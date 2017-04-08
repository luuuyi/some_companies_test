#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    string str1, str2;
    while(cin>>str1>>str2){
        map<char,int> mp({{'A',1},{'T',2},{'C',5},{'G',6}});
        int lens_1 = str1.size();
        int lens_2 = str2.size();
        if(lens_1!=lens_2||lens_1==0||lens_2==0){
            cout << 0 << endl;
            continue;
        }
        int count=0;
        for(int i=0;i<lens_1;i++){
            if(abs(mp[str1[i]]-mp[str2[i]])!=1)    ++count;
        }
        cout << count << endl;
    }
    return 0;
}