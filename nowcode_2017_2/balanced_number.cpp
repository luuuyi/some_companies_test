#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int calc(string& s){
	int lens = s.size();
	int num = 1;
	for(int i=0;i<lens;i++){
		num *= s[i]-'0';
	}
	return num;
}

bool judge(string s1, string s2){
	int left = calc(s1);
	int right = calc(s2);
	if(left==right)	return true;
	else	return false;
}

int main(){
	string str;
	while (cin >>str){
		int lens = str.size();
		if(lens<=1){
			cout << "NO" << endl;
			continue;
		}
		bool mark = false;
		for(int i=1;i<lens;i++){
			if(judge(str.substr(0,i),str.substr(i))){
				mark = true;
				break;
			}
		}
		if(mark)	cout << "YES" <<endl;
		else	cout << "NO" << endl;
	}
	return 0;
}