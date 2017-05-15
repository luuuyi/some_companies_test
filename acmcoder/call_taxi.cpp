#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector<int>>& table, vector<bool>& marks, vector<int>& dist, int n) {
    while(1){
      int idx = -1, min_dist = INT_MAX;
      for(int i=0;i<n;i++){
        if(marks[i])  continue;
        if(dist[i]<min_dist){
          min_dist = dist[i];
          idx = i;
        }
      }
      if(idx==n-1)  return dist[idx];
      marks[idx] = true;
      for(int i=0;i<n;i++){
        if(marks[i])  continue;
        if(table[idx][i]<INT_MAX&&dist[idx]+table[idx][i]<dist[i])  dist[i] = dist[idx]+table[idx][i];
      }
    }
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> table(n,vector<int>(n,INT_MAX));
	for (int i = 0; i<m; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
    table[a-1][b-1] = c; table[b-1][a-1] = c;
	}
	vector<bool> marks(n, false);
  vector<int> dist(n,INT_MAX);dist[0] = 0;
	int result = dijkstra(table, marks, dist, n);
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