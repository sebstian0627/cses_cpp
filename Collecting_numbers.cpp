#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
  int n;
  cin>>n;
  vector<int> v(n,0);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  set<int> s;
  for(int i=0;i<n;i++){
    if(v[i]==1){
      s.insert(v[i]);
    }else {
      auto it = s.find(v[i]-1);
      if(it != s.end()){
        s.erase(it);
      }

      s.insert(v[i]);
    }

  }
  cout<<s.size()<<endl;

}
