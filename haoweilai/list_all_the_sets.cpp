#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void myPrint(vector<int>& vecs){
	int lens = vecs.size();
	for(int i=0;i<lens;i++){
		if(i!=lens-1)	cout << vecs[i] << " ";
		else	cout << vecs[i];
	}
}

void myPermutation(int n, int m, int cur, int tmp_sum, vector<int> tmp, vector<vector<int>>& res){
	if(tmp_sum>=m){
		if(tmp_sum==m){
			res.push_back(tmp);
		}
		return;
	}
	for(int i=cur;i<=n;i++){
		if(tmp_sum+i<=m){
			tmp.push_back(i);
			myPermutation(n,m,i+1,tmp_sum+i,tmp,res);
			tmp.pop_back();
		}
	}
}

vector<vector<int>> getResult(int n, int m){
	vector<vector<int>> res;
	if((1+n)*n/2<m)	return res;
	vector<int> tmp;
	myPermutation(n,m,1,0,tmp,res);
	return res;
}

int main(){
	int n=0,m=0;
	while (cin >> n >> m){
		vector<vector<int>> res = getResult(n,m);
		int lens = res.size();
		for(int i=0;i<lens;i++){
			if(i!=lens-1){
				myPrint(res[i]);
				cout << endl;
			}
			else{
				myPrint(res[i]);
			}
		}
	}
	return 0;
}