#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;
  vector<pair<int,int>> end_start;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    end_start.push_back({b,a});

  }
  sort(end_start.begin(), end_start.end());

  int ans =1;
  int ending_at = end_start[0].first;
  for(int i=1;i<n;i++){
    if(ending_at<=end_start[i].second){
      ending_at = end_start[i].first;
      ans++;
    }
  }
  cout<<ans<<"\n";

  return 0;
}
