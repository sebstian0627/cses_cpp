#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


int main(){
  int n,k;
  cin>>n>>k;
  // k=(k)%n-1;
  vector<int> ans;
  ordered_set s;
  for(int i=1;i<=n;i++){
    s.insert(i);
  }
  int i=0;
  int last_erased = (k)%n+1;
  ans.push_back(last_erased);
  s.erase(last_erased);
  while(ans.size()<n){
    auto upp = s.upper_bound(last_erased);
    auto upp1 = s.order_of_key(*(upp));
    int j = (upp1 + k)%s.size();
    last_erased = *(s.find_by_order(j));
    // auto upp1 = (upp-s.begin()+k)%s.size()+s.begin();
    // last_erased = *(upp1);
    ans.push_back(last_erased);
    s.erase(last_erased);
  }
  // cout<<ans.size();
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
}
