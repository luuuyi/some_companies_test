#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
int max_P = 0x80000000;

string getResult(int n, int m){
	int tmp = n;
	string res;
	while(tmp){
		int y = tmp%m;
		tmp /= m;
		if(y>=0&&y<10)	res.push_back('0'+y);
		else	res.push_back('A'+y-10);
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	int n = 0, m = 0;
	cin >> n >> m;
	int flag = n>0?1:0;
	string res = getResult(abs(n),m);
	if(flag==1)	cout << res << endl;
	else	cout << "-" << res << endl;
	return 0;
}