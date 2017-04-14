#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string getResult(string& s1, string &s2){
	int lens_2 = s2.size();
	map<char,int> mp;
	for(int i=0;i<lens_2;i++){
		mp[s2[i]] = 1;
	}
	int lens_1 = s1.size();
	for(auto k=s1.begin();k!=s1.end();){
		if(mp.find(*k)!= mp.end()){
			auto tmp = s1.erase(k);
			k = tmp;
		}
		else	++k;
	}
	return s1;
}

int main(){
	vector<string> vecs;
	string str;
	while (getline(cin,str)){
		vecs.push_back(str);
	}
	string s = getResult(vecs[0],vecs[1]);
	cout << s << endl;
	return 0;
}