#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<int,bool>> arrivals;
  // vector<int> departs(n,0);
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    arrivals.push_back({a,true});
    arrivals.push_back({b,false});
    // cin>>arrivals[i]>>departs[i];
  }
  sort(arrivals.begin(),arrivals.end());
  int count =0;
  int max_cust = INT_MIN;
  for(int i=0;i<arrivals.size();i++){
    if(arrivals[i].second){
      count++;
      max_cust=max(max_cust, count);
    }else{
      count--;
    }
  }
  cout<<max_cust<<"\n";
  return 0;

}
