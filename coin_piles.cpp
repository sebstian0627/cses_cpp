#include<bits/stdc++.h>
using namespace std;

int main(){
  int T ;
  cin>>T;
  while(T--){
    long long int a;long long int b;
    cin>>a>>b;
    if((a+b)%3){
      cout<<"NO"<<endl;
    }else if((2*a-b)>=0 && (2*b-a)>=0){
      cout<<"YES"<<endl;

    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
