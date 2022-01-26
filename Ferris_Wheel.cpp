#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
  int n,x;

  cin>>n>>x;
    int p[n];
  for (int i=0;i<n;i++){
    cin>>p[i];
  }
  sort(p,p+n);
    int visited=0;
  int ans=0;
  int i=0;
  int j=n-1;
  while(visited<n){
    if(p[i]+p[j]<=x){
        // cout<<i<<" "<<j<<" "<<"\n";

      i++;j--;ans++;
      visited+=2;
    }else {
        // cout<<i<<" "<<j<<" "<<"\n";
      ans++;j--;
      visited+=1;

    }
    // }else{
    //
    // }
  }



cout<<ans<<" \n";
  return 0;
}
