#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
int max_P = 0x80000000;

bool getResult(vector<vector<int>>& tables, vector<vector<bool>>& flags, int P, int curx, int cury, int w, int h, vector<vector<int>> tmp){
	if (!(curx >= 0 && curx<w))	return false;
	if (!(cury >= 0 && cury<h))	return false;
	if (tables[cury][curx] == 0 || flags[cury][curx])	return false;
	if (P<0)	return false;
	if (P >= 0 && curx == w - 1 && cury == 0){
		tmp.push_back({ cury, curx });
		if (P>max_P){
			max_P = P;
			res.clear();
			res.assign(tmp.begin(), tmp.end());
		}
		tmp.pop_back();
		return true;
	}
	flags[cury][curx] = true;
	tmp.push_back({ cury, curx });
	bool ret1 = getResult(tables, flags, P - 3, curx, cury - 1, w, h, tmp);
	bool ret2 = getResult(tables, flags, P, curx, cury + 1, w, h, tmp);
	bool ret3 = getResult(tables, flags, P - 1, curx - 1, cury, w, h, tmp);
	bool ret4 = getResult(tables, flags, P - 1, curx + 1, cury, w, h, tmp);
	tmp.pop_back();
	flags[cury][curx] = false;
	return ret1 || ret2 || ret3 || ret4;
}

void myPrint(bool isEscape){
	if (isEscape){
		for (int i = 0; i<res.size(); i++){
			if (res.size() - 1 != i)	cout << "[" << res[i][0] << "," << res[i][1] << "],";
			else	cout << "[" << res[i][0] << "," << res[i][1] << "]" << endl;
		}
	}
	else	cout << "Can not escape!" << endl;
}

int main(){
	int n = 0, m = 0, P = 0;
	cin >> n >> m >> P;
	vector<vector<int>> tables(n, vector<int>(m, 0));
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++)	cin >> tables[i][j];
	}
	vector<vector<bool>> flags(n, vector<bool>(m, false));
	vector<vector<int>> tmp;
	bool isEscape = getResult(tables, flags, P, 0, 0, m, n, tmp);
	myPrint(isEscape);
	return 0;
}