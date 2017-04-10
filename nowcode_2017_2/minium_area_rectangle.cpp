#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int n=0;
	while (cin >>n){
		vector<vector<int>> points(n,vector<int>(2,0));
		int xmax = 0x80000000, xmin = 0x7fffffff;
		int ymax = 0x80000000, ymin = 0x7fffffff;
		for(int i=0;i<n;i++){
			cin >> points[i][0] >> points[i][1];
			if(points[i][0]>xmax)	xmax = points[i][0];
			if(points[i][0]<xmin)	xmin = points[i][0];
			if(points[i][1]>ymax)	ymax = points[i][1];
			if(points[i][1]<ymin)	ymin = points[i][1];
		}
		int res = (xmax-xmin)*(ymax-ymin);
		cout << res << endl;
	}
	return 0;
}