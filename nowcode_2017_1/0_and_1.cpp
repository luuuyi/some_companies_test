#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int solve(int k, int a){
	int diff = k-a;
	if(diff&0x01){
		if(k&0x01)	return 2;
		else	return -1;
	}
	else{
		if(k&0x01)	return 2;
		else	return 1;
	}
}

int main(){
	int A=0,B=0,K=0;
	while (cin >> A >> B >> K){
		int count = 0;
		if((K>A+B)&&A!=0){
			cout << -1<<endl;
			continue;
		}
		if(A==0){
			cout << 0<<endl;
			continue;
		}
		count += A/K;
		int result = 0;
		if(A%K==0){
			result = 0;
			cout << count+result << endl;
		}
		else{
			result = solve(K,A%K);
			if(result==-1)	cout << -1<<endl;
			else	cout << count+result+1 << endl;
		}
	}
	return 0;
}