#include <bits/stdc++.h>
// #include<stdio.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  int people[n];
  REP(i,n){
    cin>>people[i];
  }
  int  apartments[m];
  REP(i,m){
    cin>>apartments[i];
  }

  sort(people,people+n);
  sort(apartments,apartments+m);

  int i=0;
  int j=0;
  int count=0;
  while(i<n && j<m){
    if(abs(people[i]-apartments[j])<=k){
      count++;
      i++;
      j++;
    }else if(people[i]<apartments[j]){
      i++;
    }else{
      j++;
    }
  }
  cout<<count<<" \n";
  return 0;
}
