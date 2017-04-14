#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int getResult(vector<int>& vecs){
	sort(vecs.begin(),vecs.end());
	int lens = vecs.size();
	return vecs[(lens-1)/2];
}

int main(){
	int n=0;
	vector<int> vecs;
	while (cin >> n){
		vecs.push_back(n);
	}
	int i = getResult(vecs);
	cout << i ;
	return 0;
}