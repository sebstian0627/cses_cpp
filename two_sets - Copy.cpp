#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  long long int ans=0;
  for (int i=0;i<n;i++){
    cout<<n*n*(n*n-1)/2 - 4*(n-1)(n-2);
  }
  return 0;
  
}
