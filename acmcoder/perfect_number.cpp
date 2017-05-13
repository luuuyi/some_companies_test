#include <iostream>
#include <cmath>

bool check(int num){
  int ret = 0;
  for(int i = 1; i <= num / 2; i ++)
    if(num % i == 0)
      ret += i * i;
  ret += num * num;
  int x = sqrt((double)ret);
  if(x * x == ret)
    return true;
  return false;
}
int main(){
  using namespace std;
  int n;
  while(cin >> n){
    int ans = 0;
    for(int i = 1; i <= n; i ++)
      if(check(i))
        ans += i;
    cout << ans << endl;
  }
  return 0;
}