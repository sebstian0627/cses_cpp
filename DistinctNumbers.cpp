#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

// vector<long> merge(vector<long> a , vector<long> b){
//   vector<long> c;
//   while(!a.empty() !! !b.empty()){
//     if(a.empty()){
//       c.push_back(b.pop_back());
//     }
//     else if(b.empty()){
//       c.push_back(a.pop_back());
//     }else{
//       if(a.back()>=b.back()){
//         c.push_back(a.pop_back());
//       }else{
//         c.push_back(b.pop_back());
//       }
//     }
//   }
//   return c;
// }
//
// vector<long> sorti(vector<long> d){
//   if(d.size()==1){
//     return d;
//   }
//   else{
//
//   }
// }

int main(){
  std::ios_base::sync_with_stdio(false);
int n;
  cin>>n;
  long arr[n];
  rep(i,n){
    cin>>arr[i];
  }
  // unordered_map<long ,int> s;
  // rep(i,n){
  //   s[arr[i]]=i;
  // }
  sort(arr,arr+n);
//   rep(i,n){
//       cout<<arr[i]<<" ";
//   }
  int count=1;
  rep(i,n-1){
    if(arr[i]!=arr[i+1]){
      count++;
    }
  }
  cout<<count<<" \n";


}
