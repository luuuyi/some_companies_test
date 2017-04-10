#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
	int n=0;
	while (cin >>n){
		unordered_map<string,int> mp;
		for(int i=0;i<n;i++){
			string tmp; cin >> tmp;
			sort(tmp.begin(),tmp.end());
			mp[tmp]++;
		}
		cout << mp.size() << endl;
	}
	return 0;
}