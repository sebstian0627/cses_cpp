#include<bits/stdc++.h>
// #include<stdio.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  // long long long int ans=0;
  for (long long int i=1;i<=n;i++){
    if(i == 1){
      cout<<0<<endl;
// int128_t
    }else if(i==2){
      cout<<6<<endl;
    }else{
      cout<<((i*i*(i*i-1))/2 - 4*(i-1)*(i-2))<<endl;
    }
  }
  return 0;

}
