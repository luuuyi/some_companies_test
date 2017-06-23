#include <bits/stdc++.h>

using namespace std;

vector<int> res;

//联合多个保存状态的数组来做，
//从l点开始，当l和r相等的时候输出最终的路径
//用一个数组来维护哪些点走过，如果按照字典序最小的条件优先选择路径，如果走到一个
//已经访问过的路径，即表示为了字典序最小的话有无尽解
void dfs(vector<int>& visit, int l, int r, const vector<vector<int>>& go, const vector<int>& ok){
    if(l == r){
        for(int i=0;i<(int)res.size();i++)  printf("%c", res[i]+'a');
        cout << endl;
        exit(0);
    }
    visit[l] = 1;
    for(int i=0;i<(int)go[l].size();i++){
        int tmp = go[l][i];
        if(tmp<0 || ok[tmp]!=1)  continue;
        if(visit[tmp] == 1){
            cout << "Infinity!" << endl;
            exit(0);
        }
        res.push_back(i);
        dfs(visit, tmp, r, go, ok);
    }
}

//反向dfs，用一个数组表示，i相对应的值为1表示i点可以通过路径到n-1点
void reverseDFS(vector<int>& ok, int w, const vector<vector<int>>& reverse_go){
    ok[w] = 1;
    for(int i=0;i<(int)reverse_go[w].size();i++){
        int tmp = reverse_go[w][i];
        if(ok[tmp] != 1)    reverseDFS(ok, tmp, reverse_go);
    }
}

int main(){
    int n = 0; cin >> n;
    //用两个数组来维护送外面的状态
    //第一个数组表示i点可以通过两种方式去到的位置
    //第二个数组表示i点可以由哪些点走过来
    vector<vector<int>> go(n, vector<int>(2, 0));
    vector<vector<int>> reverse_go(n);
    //分别按规则保存每个点的状态
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            int tmp = 0; cin >> tmp;
            tmp += j;
            if(!(tmp<0 || tmp>=n)){
                go[j][i] = tmp;
                reverse_go[tmp].push_back(j);
            }
            else    go[j][i] = -1;
        }
    }
    vector<int> ok(n, 0);
    //先进行一次反向的dfs，找出哪些点可以走到最后一个点
    reverseDFS(ok, n-1, reverse_go);
    if(ok[0] != 1){
        cout << "No solution!" << endl;
        return 0;
    }
    vector<int> visit(n, 0);
    dfs(visit, 0, n-1, go, ok);
    return 0;
}