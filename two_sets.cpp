#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){

  int n;
  cin>>n;
  if(((n*(n+1))/2)%2!=0){
    cout<<"NO"<<"\n";
    return 0;
  }
  vector<int> A;
  vector<int> B;

  if(n%2==0){
    for(int i=1;i<=n/2;i++){
      if(i%2==1){
        A.push_back(i);
        A.push_back(n-i+1);
      }else{
        B.push_back(i);
        B.push_back(n-i+1);
      }
    }
  }else{
    A.push_back(1);
    A.push_back(2);
    B.push_back(3);
    int y=n-3;
    while(y>0){
      A.push_back(y+3);
      A.push_back(y+3-3);
      B.push_back(y+3-2);
      B.push_back(y+3-1);
      y=y-4;
    }
  }
  cout<<"YES\n";
  cout<<A.size()<<"\n";
  for (int i:A){
    cout<<i<<" ";
  }
  cout<<"\n";
  cout<<B.size()<<"\n";
  for (int i:B){
    cout<<i<<" ";
  }
  cout<<"\n";

  return 0;
}
