#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void print_result(vector<int>& vecs, int k){
	sort(vecs.begin(),vecs.end());
	for(int i=0;i<k;i++){
		if(i!=k-1)	cout << vecs[i] << " ";
		else	cout << vecs[i];
	}
}

int main(){
	int n=0;
	vector<int> vecs;
	while (cin >> n){
		vecs.push_back(n);
	}
	int k = vecs[vecs.size()-1];
	vecs.pop_back();
	print_result(vecs,k);
	return 0;
}