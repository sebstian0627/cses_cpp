#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,t;
  cin>>n>>t;

  vector<long long int> times(n,0);
  for(int i=0;i<n;i++){
    cin>>times[i];
  }

  long long int low = 0, high = 1e18;
  long long int bound = 1e9;
  while(low<high){
    long long int sum =0;
    long long int mid = (low +high)/2;
    for(int i=0;i<n;i++){
      sum+=min(mid/times[i], bound);
    }
    if(sum<t){
      low = mid +1 ;
    }else{
      high = mid;
    }
  }

  cout<<high<<endl;

}
