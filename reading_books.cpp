#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  int maxi = INT_MIN;
  long long int sum=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=(long long int)v[i];
    maxi = max(maxi,v[i]);
  }

  if(((long long int)maxi)*2 > sum){
    cout<<((long long int)maxi)*2<<endl;
  }else{
    cout<< sum<<endl;
  }


}
