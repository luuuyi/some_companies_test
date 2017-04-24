#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int getResult(vector<int>& vecs){
	int lens = vecs.size();
	int res = 0, max_v = 0x80000000;
	for(int i=0;i<lens;i++){
		if(res>=0){
			res += vecs[i];
		}
		else{
			res = vecs[i];
		}
		max_v = max(max_v,res);
	}
	return max_v;
}

int main(){
	int n=0;
	cin >> n;
	vector<int> vecs(n);
	for(int i=0;i<n;i++)	cin >> vecs[i];	
	int sum = getResult(vecs);
	cout << sum << endl;
	return 0;
}