#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string getMaxNumsSet(string& str){
	int lens = str.size();
	if(lens==0)	return "";
	bool is_num_has_meet = false;
	int begin=0,end=0;
	int max = 0x80000000;
	string res;
	for(int i=0;i<lens;i++){
		if(str[i]>='0'&&str[i]<='9'){
			if(!is_num_has_meet){
				begin = i;
				is_num_has_meet = true;
			}
		}
		else{
			if(is_num_has_meet){
				end = i-1;
				is_num_has_meet = false;
				if(end-begin>max){
					max = end-begin;
					res = str.substr(begin,end-begin+1);
				}
			}
		}
	}
	if(is_num_has_meet&&end<begin){
		if(lens-begin>max)	res = str.substr(begin);
	}
	return res;
}

int main(){
	string str;
	while (cin >> str){
		string res = getMaxNumsSet(str);
		cout << res << endl;
	}
	return 0;
}