#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int N = 0;
	int L = 0;
	while (cin >> N >> L){
		for(int i = L; i <= 100; i++) {
            if((2*N+i-i*i)%(2*i) == 0) {
                int start = (2*N+i-i*i)/(2*i);
                for(int j = 0; j < i-1; j++) {
                    cout<<start+j<<" ";
                }
                cout<<start+i-1;
                return 0;
            }
        }
        cout << "No" << endl;
	}
	return 0;
}