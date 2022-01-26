#include<bits/stdc++.h>
using namespace std;

// idea is to find the just greater tower head.
// use upper bound to find and then replace it.
int main(){
  int n;
  cin>>n;
  std::vector<int> v(n,0);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  multiset<int> s;
  s.insert(v[0]);
  int count =1;

  for(int i=1;i<n;i++){
    auto upp = s.upper_bound(v[i]);
    if(upp==s.end()){
      count++;
      // s.insert(v[i]);
    }else{
      s.erase(upp);
    }
    s.insert(v[i]);

  }

  cout<<count<<endl;


}
