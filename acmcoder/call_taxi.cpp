#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void myPermutation(map<int, vector<vector<int>>>& table, vector<bool>& marks, int cur, int dst, int cur_dist, int& result) {
	if (cur == dst) {
		if (cur_dist<result)	result = cur_dist;
		return;
	}
	for (int i = 0; i<table[cur].size(); i++) {
		if (!marks[table[cur][i][0]]) {
			if(cur_dist + table[cur][i][1]>result)	continue;
			marks[table[cur][i][0]] = true;
			myPermutation(table, marks, table[cur][i][0], dst, cur_dist + table[cur][i][1], result);
			marks[table[cur][i][0]] = false;
		}
	}
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	map<int, vector<vector<int>>> table;
	for (int i = 0; i<m; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		table[a - 1].push_back(vector<int>({ b - 1,c }));
		table[b - 1].push_back(vector<int>({ a - 1,c }));
	}
	vector<bool> marks(n, false); marks[0] = true;
	int result = 0x7fffffff;
	myPermutation(table, marks, 0, n - 1, 0, result);
	cout << result << endl;
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int> > mp(n+1,vector<int>(n+1,INT_MAX));
  int p1,p2,l;
  for(int i=0;i<m;++i){
    cin>>p1>>p2>>l;
    mp[p1][p2]=l;
    mp[p2][p1]=l;
  }
  vector<int> dis(n+1,INT_MAX);
  vector<bool> visited(n+1,false);
  dis[1]=0;
  while(1){
    int index=-1;
    int mind=INT_MAX;
    for(int i=1;i<=n;++i){
      if(visited[i])continue;
      if(dis[i]<mind){
        mind=dis[i];
        index=i;
      }
    }
    if(index==n){
      cout<<dis[index]<<endl;
      return 0;
    }
    visited[index]=true;
    for(int i=1;i<=n;++i){
      if(visited[i])continue;
      if(mp[index][i]<INT_MAX&&dis[i]>dis[index]+mp[index][i]){
        dis[i]=dis[index]+mp[index][i];
      }
    }
  }
  return 0;
}
*/