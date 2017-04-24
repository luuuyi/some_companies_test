#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int getResult(int n){
	int res = 0, tmp = n;
	while(tmp){
		res += tmp/5;
		tmp /= 5;
	}
	return res;
}

int main(){
	int n = 0;
	cin >> n;
	int ret = getResult(n);
	cout << ret << endl;
	return 0;
}