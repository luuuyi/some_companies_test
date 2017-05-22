#include <bits/stdc++.h>

using namespace std;

int getResult(string& s1, string& s2){
	int lens_1 = s1.size(), lens_2 = s2.size();
	int ret = 0x3f3f3f3f;
	if(lens_1 == lens_2){
		int count = 0;
		for(int i=0;i<lens_1;i++){
			if(s1[i]!=s2[i])	++count;
		}
		ret = min(ret, count);
	}
	else{
		for(int i=0;i<=lens_2 - lens_1;i++){
			int count = 0;
			for(int j=0;j<lens_1;j++){
				if(s1[j]!=s2[i+j])	++count;
			}
			ret = min(count, ret);
		}
	}
	return ret;
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	cout << getResult(s1, s2) << endl;
	return 0;
}