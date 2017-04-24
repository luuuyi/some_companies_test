#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a,vector<int> b){
	if(a[1]==b[1])	return a[0]<b[0];
	return a[1] < b[1];
}

long long getResult(vector<int>& tables, vector<vector<int>>& consumers){
	long long  total = 0;
	sort(tables.begin(),tables.end());
	sort(consumers.begin(),consumers.end(),cmp);
	int count = 0, table_size = tables.size();
	vector<bool> isHasConsumer(table_size,false);
	for(int i=consumers.size()-1;i>=0&&count!=table_size;i--){
		for(int j=0;j<table_size;j++){
			if(tables[j]>=consumers[i][0]&&!isHasConsumer[j]){
				total += consumers[i][1];
				isHasConsumer[j] = true;
				count++;
				break;
			}
		}
	}
	return total;
	/*for(int i=0;i<tables.size();i++){
		int now_table = tables[i];
		int max_consume = -1, index = -1;
		for(int j=0;j<consumers.size()&&consumers[j][0]<=now_table;j++){
			if(consumers[j][1]>=max_consume){
				max_consume = consumers[j][1];
				index = j;
			}
		}
		if(index!=-1){	
			total += consumers[index][1];
			consumers.erase(consumers.begin()+index);
		}
	}
	return total;*/
}

int main(){
	int n=0,m=0;
	cin >> n >> m;
	vector<int> tables(n);
	vector<vector<int>> consumers(m,vector<int>(2,0));
	for(int i=0;i<n;i++)	cin >> tables[i];	
	for(int i=0;i<m;i++)	cin >> consumers[i][0] >> consumers[i][1];
	long long sum = getResult(tables,consumers);
	cout << sum << endl;
	return 0;
}