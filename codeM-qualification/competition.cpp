#include <bits/stdc++.h>

using namespace std;

//二分查找的实现
int binarySearch(vector<int>& points, int l, int r, int target){
    while(l <= r){
        int mid = l + (r-l)/2;
        if(points[mid] == target)   return mid;
        else if(points[mid] > target)   r = mid - 1;
        else    l = mid + 1;
    }
    return -1;
}

//求解子函数
int getResult(vector<int>& points, int n){
    int person = points[0];
    sort(points.begin(), points.end());
    int index = binarySearch(points, 0, n-1, person);
    return log2(index+1);
}

//找到参赛者最多能参加多少轮比赛
//每个参赛者的分数都不一样，所以可以先排序，然后用二分法找到小明的段位位置
//最终参赛轮数经过测试为log2(段位)
int main(){
    int n = 0;
    cin >> n;
    vector<int> points(n, 0);
    for(int i=0;i<n;i++)    cin >> points[i];
    cout << getResult(points, n) << endl;
    return 0;
}