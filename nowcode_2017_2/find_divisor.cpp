#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int getResult(int left, int right, int divisor){
	int min = ceil((double)left/divisor);
	int max = floor((double)right/divisor);
	return max-min+1;
}

int main(){
	int left=0,right=0,divisor=0;
	while (cin >>left>>right>>divisor){
		int n = getResult(left,right,divisor);
		cout << n << endl;
	}
	return 0;
}