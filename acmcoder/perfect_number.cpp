#include <iostream>
#include <cmath>

using namespace std;

/*bool check(int num){
  int ret = 0;
  for(int i = 1; i <= num / 2; i ++)
    if(num % i == 0)
      ret += i * i;
  ret += num * num;
  int x = sqrt((double)ret);
  if(x * x == ret)
    return true;
  return false;
}*/

bool isValid(int n){
  long long ans = n*n;
  for(int i=1;i<=n/2;i++){
    if(n%i==0)  ans += i*i;
  }
  long long x = sqrt(ans);
  if(x*x==ans)  return true;
  else return false;
}

int main(){
  int n;
  cin >> n;
  long long ans = 0;
  for(int i=1;i<=n;i++){
    if(isValid(i))  ans += i;
  }
  cout << ans << endl;
  return 0;
}