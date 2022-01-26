#include<bits/stdc++.h>
using namespace std;


int main(){
  long long int n;
  cin>>n;
  long long int zeros = 0;
  long long int pow5 =5;
  while(pow5<=n){
    zeros+=n/pow5;
    pow5*=5;
  }
  cout<<zeros<<endl;
  return 0;
}
