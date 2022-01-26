#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  vector<int> vi(n,0);
  for(int i=0;i<n;i++){
    cin>>vi[i];
  }
  map<int,int> m;
  int maxlen = INT_MIN;
  int start = 0;
  for(int i=0;i<n;i++){
    // cout<<start<<" "<<i<<endl;
    if(m.find(vi[i])!=m.end()){
      start = max(start,m[vi[i]]+1);
    }
    m[vi[i]]=i;
    maxlen=max(maxlen,i-start+1);
  }




  cout<<maxlen<<endl;


}
