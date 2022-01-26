#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<int> ans;
  vector<bool> boo(n,false);
  int i=0;
  while(ans.size()<n){
    while(boo[i]){
      i=(i+1)%n;
    }
    i=(i+1)%n;
    while(boo[i]){
      i=(i+1)%n;
    }
    boo[i]=true;
    ans.push_back(i+1);
  }

  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
}
