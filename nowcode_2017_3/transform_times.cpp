#include <bits/stdc++.h>

using namespace std;

int getResult(int n){
	string tmp = to_string(n);
	int ret = 0;
	while(tmp.size()>1){
		long long tmp_x = 1;
		for(int i=0;i<tmp.size();i++){
			tmp_x *= tmp[i] - '0';
		}
		tmp = to_string(tmp_x);
		++ret;
	}
	return ret;
}

int main(){
	int n = 0;
	cin >> n;
	cout << getResult(n) << endl;
	return 0;
}