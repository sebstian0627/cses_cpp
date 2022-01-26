#include<bits/stdc++.h>
using namespace std;

int main(){

  int x,n;
  cin>>x>>n;

  vector<int> l (n,0);
  set<int> ll{0,x};

  for(int i=0;i<n;i++){
      cin>>l[i];
      ll.insert(l[i]);
  }
  int maxlen=0;
  int prev = 0;
  vector<int> gaps;
  for( int i : ll){
    maxlen = max(maxlen, i-prev);
    prev=i;
    // cout<<i<<endl;
  }
  gaps.push_back(maxlen);

  for(int i=n-1;i>0;i--){
    ll.erase(l[i]);
    auto upp = ll.upper_bound(l[i]);
    int h = *(upp);
    int lo = *(--upp);
    // cout<<h<<' '<<lo<<endl;
    maxlen = max(maxlen,h-lo);
    gaps.push_back(maxlen);
  }
  reverse(gaps.begin(), gaps.end());
  for(int i=0;i<n;i++){
    cout<<gaps[i]<<" ";
  }



}
