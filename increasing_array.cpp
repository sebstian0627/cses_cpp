#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long int arr[n];
  for (int i=0;i<n;i++){
    cin>>arr[i];
  }
  long long int moves=0;
  for (int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
      moves+=(arr[i]-arr[i+1]);
      arr[i+1]=arr[i];
    //   cout<<moves<<"m\n";
    }
  }

  cout<<moves<<"\n";
  return 0;
}
