#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){

  vector<int> counter;

  string x;
  cin>>x;
  int temp=0;
  for (int i=0;i<x.size()-1;i++){
    temp=1;
    while(x[i]==x[i+1]){
      temp++;
      i++;
    }
    counter.push_back(temp);
  }
  int max=-1;
  for (int i: counter){
    if(i>max){
      max=i;
    }
  }
  if(max==-1){
    cout<<x.size()<<"\n";
  }else{
  cout<<max<<"\n";}
  return 0;
}
