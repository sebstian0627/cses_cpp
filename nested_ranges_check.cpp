#include<bits/stdc++.h>
using namespace std;

bool compareRange(pair<int,int> &a, pair<int,int>&b){
  return (a.second-a.first)<(b.second - b.first);
}

// 

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> v;
  map<pair<int,int>,int> index;
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    v.push_back({a,b});
    index[{a,b}]=i;
  }
  sort(v.begin(),v.end(),compareRange);


}
