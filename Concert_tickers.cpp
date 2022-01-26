#include <bits/stdc++.h>
// #include<stdio.h>

using namespace std;

// long long int binSearch(vector<long long int> &prices, vector<long long int> &sold, long long int price){
//   int l=0;
//   int r = (int) prices.size()-1;
//   while(l<=r){
//     int mid = (l-r)/2 + l;
//     if(prices[mid] == price && !sold[mid] ){
//       sold[mid]=true;
//       return prices[mid];
//     }
//     else if(prices[mid] <  )
//   }
// }


int main(){
  int n,m;
  cin>>n>>m;
  multiset<long long int> tickets;
  vector<bool> sold(n,0);
  // vector<long long int> claims(m,0);
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;tickets.insert(temp);
  }

  for(int i=0;i<m;i++){
    int temp;cin>>temp;
    auto it = tickets.upper_bound(temp);
    if(it == tickets.begin()){
      cout<<-1<<"\n";
    }else{
      cout<<*(--it)<<"\n";
      tickets.erase(it);
    }
  }

}
